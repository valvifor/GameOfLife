#ifndef GAMELIFE_PARSER_H
#define GAMELIFE_PARSER_H

#include "Field.h"
#include "Command.h"

enum class Commands{
    reset, set, clear, step, back, save, load, ERROR
};

class Parser {
public:
    Commands getCommand(const string&);
};

class Game{
private:
    Command command;
    Parser parser;
public:
    Game() = default;
    void game();
};

#endif //GAMELIFE_PARSER_H
