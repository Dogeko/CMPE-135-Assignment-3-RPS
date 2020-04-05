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
    void playRound();
    int getRound(){
    	return round;
    }

    void setRound(int rounds){
    	round = rounds;
    }

    int getHumanWins(){ return humanWins; }

    void addHumanWin(){ humanWins = humanWins + 1; }

    int getBotWins(){ return botWins; }

    void addBotWin(){ botWins = botWins + 1; }

    int getDraws(){ return Draws; }

    void addDraw(){ Draws = Draws + 1; }

};

#endif
