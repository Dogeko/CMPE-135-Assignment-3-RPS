#ifndef CHARGES1_H
#define CHARGES1_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
#include "StateAI.h"

using namespace std;

class Charges1 : public actionState
{
private:
	StateAI AI

public:

	Charges1(StateAI *AI_ptr) : AI(AI_ptr) {}
	virtual ~Charges1(){}
	void pick(int botChoice);
};

#endif
