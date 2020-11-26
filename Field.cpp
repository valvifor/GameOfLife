#include "Field.h"

Field::Field() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            space1[i][j] = '.';
            space2[i][j] = '.';
        }
    }
}

Field::~Field(){

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
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            swap(space2[i][j], space1[i][j]);
        }
    }
}

void Field::back() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            swap(space2[i][j], space1[i][j]);
        }
    }
}

void Field::save(ofstream &output) {
    for (size_t i = 0; i < spaceHeight; i++){
        for (size_t j = 0; j < spaceWidth; j++){
            output << space2[i][j] << " ";
        }
        output << endl;
    }
}

void Field::load(std::ifstream &input) {
    char cell;
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            input >> cell;
            space1[i][j] = cell;
            space2[i][j] = cell;
        }
    }
}

char Field::cellContent(int &X, int &Y) {
    return space1[X][Y];
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
                if (space2[x][y] == '*') {
                    count++;
                }
            } else if (X + i < 0 && Y + j >= 0){
                int x = 9, y = (Y + j) % spaceHeight;
                if (space2[x][y] == '*') {
                    count++;
                }
            }else if (X + i >= 0 && Y + j < 0){
                int x = (X + i) % spaceWidth, y = 9;
                if (space2[x][y] == '*') {
                    count++;
                }
            } else {
                int x = (X + i) % spaceWidth;
                int y = (Y + j) % spaceHeight;
                if (space2[x][y] == '*') {
                    count++;
                }
            }
        }
    }
    return count;
}