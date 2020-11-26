#include "Parser.h"

string Parser::getCommand() {
    string command;
    cin >> command;
    return command;
}

void Parser::getCommand(Parser &input) {
    string cmd = input.getCommand();
    if (cmd == "reset"){
        space.reset();
    } else if(cmd.substr(0,3) == "set"){
        int X = cmd[3] - 65;
        int Y = cmd[4] - 48;
        space.set(X, Y);
    } else if(cmd.substr(0,5) == "clear"){
        int X = cmd[5] - 65;
        int Y = cmd[7] - 48;
        space.clear(X, Y);
    } else if (cmd.substr(0, 4) == "back"){
        space.back();
    } else if(cmd.substr(0, 4) == "step"){

    } else if(cmd.substr(0, 4) == "save"){
        space.save();
    } else if(cmd.substr(0, 4) == "load"){
        space.load();
    } else cout << "Wrong command";
}
