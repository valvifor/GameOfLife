#ifndef GAMELIFE_PARSER_H
#define GAMELIFE_PARSER_H

#include "Field.h"

class Parser{
private:
    Field space;
public:
    string getCom();
    void getCommand();
};


#endif //GAMELIFE_PARSER_H
