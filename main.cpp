#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Parser.h"
#include "Field.h"

using namespace std;

TEST(TestSet, test1){
    Field game;
    int x = 6;
    game.set(x, x);
    EXPECT_EQ('*', game.cellContent(x, x));
}

TEST(TestSet, test2){
    Field game;
    int x = 6;
    int y = 3;
    game.set(x, y);
    EXPECT_EQ('*', game.cellContent(x, y));
}

TEST(TestClear, test3){
    Field game;
    int x = 5;
    game.set(x, x);
    game.clear(x, x);
    EXPECT_EQ('.', game.cellContent(x, x));
}

TEST(TestClear, test4){
    Field game;
    int x = 5;
    int y = 9;
    game.set(x, y);
    game.clear(x, y);
    EXPECT_EQ('.', game.cellContent(x, y));
}

TEST(TestStep, test5){
    Field game;
    int x = 3;
    game.set(x, x);
    game.step();
    EXPECT_EQ('.', game.cellContent(x, x));
}

TEST(TestNeighbors, test6){
    Field game;
    int x = 1;
    game.set(x, x);
    x++;//2
    game.set(x, x);
    x++;//3
    game.set(x, x);
    game.step();
    EXPECT_EQ(game.numberOfLiveNeighbors(x, x), 1);
    x--;//2
    EXPECT_EQ(game.numberOfLiveNeighbors(x, x), 2);
}

TEST(TestStep, test7){
    Field game;
    int x = 1;
    game.set(x, x);
    x++;//2
    game.set(x, x);
    x++;//3
    game.set(x, x);
    game.step();
    EXPECT_EQ('.', game.cellContent(x, x));
    x--;//2
    EXPECT_EQ('.', game.cellContent(x, x));
    x--;//1
    EXPECT_EQ('.', game.cellContent(x, x));
}

TEST(TestStep, test8){
    Field game;
    int x = 6;
    int y = 7;
    int a = 6;
    int b = 8;
    game.set(x, x);
    game.set(y, y);
    game.set(a, b);
    game.step();
    EXPECT_EQ('.', game.cellContent(y, y));
}

TEST(TestReset, test9){
    Field game;
    for (int i = 0; i < spaceHeight; i++){
        game.set(i, i);
    }
    game.reset();
    for (int i = 0; i < spaceHeight; i++){
        for (int j = 0; j < spaceWidth; j++){
            EXPECT_EQ('.', game.cellContent(i, i));
        }
    }
}

TEST(BackTest, test10){
    Field game;
    int x = 6;
    int y = 7;
    int a = 6;
    int b = 8;
    game.set(x, x);
    game.set(y, y);
    game.set(a, b);
    game.step();
    game.back();
    EXPECT_EQ('.', game.cellContent(x, y));
}

TEST(TestStep, test11){
    Field game;
    for (int i = 0; i < spaceHeight; i++) {
        for (int j = 0; j < spaceWidth; j++) {
            if (i != j)
                game.set(i, j);
        }
    }
    cout << game;
    for (int i = 0; i < 1001; i++){
        game.step();
    }
    cout << game;
}

int main() {
    Game game;
    game.game();
}
