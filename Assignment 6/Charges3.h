#ifndef CHARGES3_H
#define CHARGES3_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
#include "StateAI.h"

using namespace std;

class Charges3 : public actionState
{
private:
	stateAI *AI;
public:

	Charges3(StateAI *AI_ptr) : AI(AI_ptr) {}
	virtual ~Charges3(){}

	void pick(int botChoice);
};

#endif
