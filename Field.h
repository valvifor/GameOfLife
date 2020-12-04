#ifndef GAMELIFE_FIELD_H
#define GAMELIFE_FIELD_H

#include <iostream>
#include <fstream>

using namespace std;

const int spaceWidth = 10;
const int spaceHeight = 10;

class Field{
private:
    char space1[spaceWidth][spaceHeight];
    char space2[spaceWidth][spaceHeight];
    int stepCounter = 0;
    bool canBack = false;
    bool gameOver = false;
public:
    Field();
    ~Field();

    friend ostream &operator<<(ostream&, const Field&);

    void reset();
    void set(int&, int&);
    void clear(int&, int&);
    void step();
    void back();
    void save(const string &);
    void load(const string &);

    char cellContent(int&, int&);
    int numberOfLiveNeighbors(int&, int&);
    void lifeField();
    void lifeCell(int&, int&);
    bool equal();
};

#endif //GAMELIFE_FIELD_H
