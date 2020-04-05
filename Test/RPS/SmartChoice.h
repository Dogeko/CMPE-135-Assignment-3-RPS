#ifndef SMARTCHOICE_H
#define SMARTCHOICE_H

#include <iostream>
#include "Database.h"
#include "Bot.h"
using namespace std;

class SmartChoice : public Bot
{

private:
    Database records;
    string foundSequence;
    int smart_choice[5]= {3};

public:
    void pick(int playerChoice, int prediction);
};

#endif
