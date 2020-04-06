#ifndef BOTFACTORY_H
#define BOTFACTORY_H

#include <iostream>
#include "Bot.h"
using namespace std;

class BotFactory : public Bot
{
public:
    static Bot *pickAlgo(char choice);
};

#endif