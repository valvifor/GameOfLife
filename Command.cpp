#include "Command.h"

bool Command::isOver(){
    return over;
}

void Command::reset() {
    canBack = false;
    stepCounter = 0;
    space.reset();
    cout << space;
    cout << "Number of steps: " << stepCounter << endl;
}

void Command::set(const string &cmd) {
    int X = cmd[3] - 65;
    int Y = cmd[4] - 48;
    canBack = false;
    space.set(Y, X);
    cout << space;
    cout << "Number of steps: " << stepCounter << endl;
}

void Command::clear(const string &cmd) {
    int X = cmd[5] - 65;
    int Y = cmd[6] - 48;
    canBack = false;
    space.clear(Y, X);
    cout << space;
    cout << "Number of steps: " << stepCounter << endl;
}


void Command::step(const string &cmd) {
    canBack = true;
    space.step();
    stepCounter++;
    for (int i = 0; i < spaceHeight; i++) {
        for (int j = 0; j < spaceWidth; j++) {
            space.lifeCell(j, i);
        }
    }
    cout << space;
    cout << "Number of steps: " << stepCounter << endl;
    if (space.equal()){
        over = true;
        cout << "Game over" << endl;
        return;
    }
}

void Command::back() {
    if (canBack) {
        space.back();
        stepCounter--;
        canBack = false;
        cout << space;
        cout << "Number of steps: " << stepCounter << endl;
    } else {
        cout << "Error" << endl;
    }
}

void Command::save(const string &cmd) {
    string name = cmd.substr(5) + ".txt";
    ofstream file;
    file.open(name);
    space.save(file);
    file.close();
}

void Command::load(const string &cmd) {
    string name = cmd.substr(5) + ".txt";
    ifstream file;
    file.open(name);
    if (file.is_open()){
        stepCounter = 0;
        canBack = false;
        space.load(file);
        cout << space;
        cout << "Number of steps: " << stepCounter << endl;
    } else {
        cout << "ERROR" << endl;
    }
    file.close();
}
