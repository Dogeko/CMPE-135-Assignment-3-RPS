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
    int foundSequence;

public:
    void pick(int playerChoice);
};

#endif