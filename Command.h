#ifndef GAMELIFE_COMMAND_H
#define GAMELIFE_COMMAND_H

#include "Field.h"
#include <iostream>

using namespace std;

class Command {
private:
    Field space;
    int stepCounter = 0;
    bool canBack = false;
    bool over = false;
public:
    Command() = default;
    bool isOver();
    void reset();
    void set(const string &);
    void clear(const string &);
    void step(const string &);
    void back();
    void save(const string &);
    void load(const string &);
};


#endif //GAMELIFE_COMMAND_H
