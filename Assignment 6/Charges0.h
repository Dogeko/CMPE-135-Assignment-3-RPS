#ifndef CHARGES0_H
#define CHARGES0_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
#include "StateAI.h"

using namespace std;

class Charges0 : public actionState
{
private:
	StateAI AI

public:

	Charges0(StateAI *AI_ptr) : AI(AI_ptr) {}
	virtual ~Charges0(){}
	void pick(int botChoice);
};

#endif
