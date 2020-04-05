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
    int round = 20;
    int humanWins = 0;
    int botWins = 0;
    int Draws = 0;
    bool check = true;
public:
    Human human;
    Bot *bot = BotFactory::pickAlgo('S');
    void play();
    int result(int humanChoice, int botChoice);
    void printResult(int result);
    int getRound();
    void setRound(int rounds);
    int getHumanWins();
    void addHumanWin();
    int getBotWins();
    void addBotWin();
    int getDraws();
    void addDraw();
};

#endif
