#ifndef STATEAI
#define STATEAI

#include <iostream>
#include "Bot.h"
#include "actionState.h"
using namespace std;

class StateAI : public Bot
{
public:
	void pick(int botChoice);
};

#endif
