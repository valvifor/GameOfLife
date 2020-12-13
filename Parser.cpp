#include "Parser.h"

void Game::game() {
    string cmd;
    while (!command.isOver()) {
        getline(cin, cmd);
        switch (parser.getCommand(cmd)) {
            case Commands::reset:
                command.reset();
                break;
            case Commands::set:
                command.set(cmd);
                break;
            case Commands::clear:
                command.clear(cmd);
                break;
            case Commands::back:
                command.back();
                break;
            case Commands::step:
                if (cmd.length() == 4) {
                    command.step(cmd);
                } else {
                    for (int i = 0; i < stoi(cmd.substr(4)); i++) {
                        command.step(cmd);
                    }
                }
                break;
            case Commands::save:
                command.save(cmd);
                break;
            case Commands::load:
                command.load(cmd);
                break;
            default:
                cout << "Wrong command";
        }
    }
}

Commands Parser::getCommand(const string &cmd) {
    if (cmd == "reset"){
        return Commands::reset;
    } else if (cmd.substr(0, 3) == "set"){
        return Commands::set;
    } else if (cmd.substr(0, 5) == "clear") {
        return Commands::clear;
    } else if (cmd.substr(0, 4) == "back") {
        return Commands::back;
    } else if (cmd.substr(0, 4) == "step") {
        return Commands::step;
    } else if (cmd.substr(0, 4) == "save") {
        return Commands::save;
    } else if (cmd.substr(0, 4) == "load") {
        return Commands::load;
    }
    return Commands::ERROR;
}
