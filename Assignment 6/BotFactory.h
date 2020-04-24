#ifndef BOTFACTORY_H
#define BOTFACTORY_H

#include <iostream>
#include "Bot.h"
#include "RandomAI"
#include "StateAI"
using namespace std;

class BotFactory : public Bot
{
public:
	static Bot *pickAlgo(char algo_type);
};
#endif
