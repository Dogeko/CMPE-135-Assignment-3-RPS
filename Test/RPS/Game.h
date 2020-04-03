#ifndef GAME_H
#define GAME_H

#include "Human.h"
#include "Bot.h"
#include "BotFactory.h"
#include <iostream>
using namespace std;

class Game
{
private:
    int round;
    Human human;
    Bot *bot;
    bool check = true;
public:
    void play();
    int result(int humanChoice, int botChoice);
    void printResult(int result);
};

#endif
