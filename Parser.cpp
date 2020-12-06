#include "Parser.h"

string Parser::getCom() {
    string command;
    getline(cin, command);
    return command;
}

void Parser::getCommand() {
    string cmd = getCom();
    while (cmd != "exit") {
        if (cmd == "reset") {
            space.reset();
        } else if (cmd.substr(0, 3) == "set") {
            int X = cmd[3] - 65;
            int Y = cmd[4] - 48;
            space.set(Y, X);
        } else if (cmd.substr(0, 5) == "clear") {
            int X = cmd[5] - 65;
            int Y = cmd[6] - 48;
            space.clear(Y, X);
        } else if (cmd.substr(0, 4) == "back") {
            space.back();
        } else if (cmd.substr(0, 4) == "step") {
            if (cmd.length() == 4){
                space.step();
            } else {
                for (int i = 0; i < stoi(cmd.substr(5)); i++){
                    space.step();
                }
            }
            if (space.equal()){
                cout << "Game is over" << endl;
                break;
            }
        } else if (cmd.substr(0, 4) == "save") {
            string name = cmd.substr(5);
            space.save(name);
        } else if (cmd.substr(0, 4) == "load") {
            string name = cmd.substr(5);
            space.load(name);
        } else cout << "Wrong command";
        cout << space;
    }
}
