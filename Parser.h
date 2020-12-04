#ifndef GAMELIFE_PARSER_H
#define GAMELIFE_PARSER_H

#include "Field.h"

class Parser{
private:
    Field space;
public:
    static string getCommand();
    string getCommand(Parser&);
};


#endif //GAMELIFE_PARSER_H
