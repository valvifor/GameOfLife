#ifndef GAMELIFE_PARSER_H
#define GAMELIFE_PARSER_H

#include "Field.h"

class Parser{
private:
    Field space;
public:
    string getCommand();
    void getCommand(Parser&);
};


#endif //GAMELIFE_PARSER_H
