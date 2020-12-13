#include "Field.h"

Field::Field() {
    space1 = new char*[spaceHeight];
    space2 = new char*[spaceHeight];
    for (int i = 0; i < spaceHeight; i++){
        space1[i] = new char[spaceWidth];
        space2[i] = new char[spaceWidth];
        for (int j = 0; j < spaceWidth; j++){
            space1[i][j] = '.';
            space2[i][j] = '.';
        }
    }
}

Field::~Field(){
    for (int i = 0; i < spaceHeight; i++){
        delete [] space1[i];
        delete [] space2[i];
    }
    delete [] space1;
    delete [] space2;
}

ostream &operator<<(ostream &output, const Field &field) {
    output << "  A B C D E F G H I J" << endl;
    for (int i = 0; i < spaceHeight; i++){
        output << i << " ";
        for (int j = 0; j < spaceWidth ; j++){
            output << field.space2[i][j] << " ";
        }
        output << endl;
    }
    return output;
}

void Field::reset() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            space2[i][j] = '.';
        }
    }
}

void Field::set(int &X, int &Y) {
    space2[X][Y] = '*';
}

void Field::clear(int &X, int &Y) {
    space2[X][Y] = '.';
}

void Field::step() {
    swap(space2, space1);
}

void Field::back() {
    swap(space2, space1);
}

void Field::save(ofstream &output) {
    for (size_t i = 0; i < spaceHeight; i++){
        for (size_t j = 0; j < spaceWidth; j++){
            output << space2[i][j] << " ";
        }
        output << endl;
    }
}

void Field::load(ifstream &input) {
    int x = 0;
    int y = 0;
    char c;
    input >> c;
    while (input){
        space2[y][x] = c;
        space1[y][x] = c;
        if (++x == spaceWidth){
            x = 0;
            y++;
        }
        input >> c;
    }
}

char Field::cellContent(int &X, int &Y) {
    return space2[X][Y];
}

int Field::numberOfLiveNeighbors(int &X, int &Y) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == j && i == 0){
                continue;
            }
            if (X + i < 0 && Y + j < 0){
                int x = 9, y = 9;
                if (space1[x][y] == '*') {
                    count++;
                }
            } else if (X + i < 0 && Y + j >= 0){
                int x = 9, y = (Y + j) % spaceHeight;
                if (space1[x][y] == '*') {
                    count++;
                }
            }else if (X + i >= 0 && Y + j < 0){
                int x = (X + i) % spaceWidth, y = 9;
                if (space1[x][y] == '*') {
                    count++;
                }
            } else {
                int x = (X + i) % spaceWidth;
                int y = (Y + j) % spaceHeight;
                if (space1[x][y] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}

void Field::lifeCell(int &X, int &Y) {
    if ((space1[X][Y] == '.') && (numberOfLiveNeighbors(X, Y) == 3)){
        space2[X][Y] = '*';
    } else if ((space1[X][Y] == '*') && (numberOfLiveNeighbors(X, Y) < 2 || numberOfLiveNeighbors(X, Y) > 3)) {
        space2[X][Y] = '.';
    } else {
        space2[X][Y] = space1[X][Y];
    }
}

bool Field::equal() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            if (space1[i][j] != space2[i][j]){
                return false;
            }
        }
    }
    return true;
}

