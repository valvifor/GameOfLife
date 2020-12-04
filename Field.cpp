#include "Field.h"

Field::Field() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            space1[i][j] = '.';
            space2[i][j] = '.';
        }
    }
}

Field::~Field()= default;

ostream &operator<<(ostream &output, const Field &field) {
    output << "  A B C D E F G H I J" << endl;
    for (int i = 0; i < spaceHeight; i++){
        output << i << " ";
        for (int j = 0; j < spaceWidth ; j++){
            output << field.space2[i][j] << " ";
        }
        output << endl;
    }
    output << "Number of steps: " << field.stepCounter << endl;
    return output;
}

void Field::reset() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            space2[i][j] = '.';
        }
    }
    canBack = false;
    stepCounter = 0;
}

void Field::set(int &X, int &Y) {
    space2[X][Y] = '*';
    canBack = false;
}

void Field::clear(int &X, int &Y) {
    space2[X][Y] = '.';
    canBack = false;
}

void Field::step() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            swap(space2[i][j], space1[i][j]);
        }
    }
}

void Field::back() {
    if (canBack) {
        for (int i = 0; i < spaceHeight; i++) {
            for (int j = 0; j < spaceWidth; j++) {
                swap(space2[i][j], space1[i][j]);
            }
        }
        stepCounter--;
        canBack = false;
    } else {
        cout << "Error" << endl;
    }
}

void Field::save(const string &output) {
    string name = output + ".txt";
    ofstream file;
    file.open(name);
    for (size_t i = 0; i < spaceHeight; i++){
        for (size_t j = 0; j < spaceWidth; j++){
            file << space2[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void Field::load(const string &input) {
    string name = input + ".txt";
    ifstream file;
    file.open(name);
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            file >> space2[i][j];
        }
    }
    file.close();
    stepCounter = 0;
    canBack = false;
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

void Field::lifeCell(int &X, int &Y) {
    if ((space1[X][Y] == '.') && (numberOfLiveNeighbors(X, Y) == 3)){
        space2[X][Y] = '*';
    } else if ((space1[X][Y] == '*') && (numberOfLiveNeighbors(X, Y) < 2 || numberOfLiveNeighbors(X, Y) > 3)) {
        space2[X][Y] = '.';
    }
}

void Field::lifeField() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            space1[i][j] = space2[i][j];
        }
    }
    for (int i = 0; i < spaceHeight; i++) {
        for (int j = 0; j < spaceWidth; j++) {
            lifeCell(i, j);
        }
    }
    stepCounter++;
}

bool Field::equal() {
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            if (space1[i][j] == space2[i][j]){
                return true;
            }
        }
    }
    return false;
}
