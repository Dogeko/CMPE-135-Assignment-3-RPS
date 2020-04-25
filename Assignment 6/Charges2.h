#ifndef CHARGES2_H
#define CHARGES2_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
#include "StateAI.h"

using namespace std;

class Charges2 : public actionState
{
private:
	StateAI AI

public:

	Charges2(StateAI *AI_ptr) : AI(AI_ptr) {}
	virtual ~Charges2(){}
	void pick(int botChoice);
};

#endif
