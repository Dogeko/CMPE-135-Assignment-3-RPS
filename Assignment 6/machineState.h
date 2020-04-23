#ifndef GAME_H
#define GAME_H

#include "Human.h"
#include "Bot.h"
using namespace std;

class machineState
{
private:
    Human human;
    Bot *bot;
public:
    int noCharge(int humanCharge);
    int haveCharges(int humanCharge);
    int actionState(int humanCharge);
};