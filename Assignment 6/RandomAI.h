#ifndef RANDOMAI_H
#define RANDOMAI_H

#include <iostream>
#include "Bot.h"
using namespace std;

class RandomAI : public Bot
{

public:
	void pick(int botChoice);
};
#endif