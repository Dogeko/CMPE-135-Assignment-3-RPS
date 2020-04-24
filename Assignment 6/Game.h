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
    Human human;
    Bot *bot;
    bool gameOver = false;
public:
    void play();
    void endGame();
    int result(int humanChoice, int BotChoice);
    void displayResult(int result);

};

#endif
