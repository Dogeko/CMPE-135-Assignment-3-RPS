#ifndef STATEAI
#define STATEAI

#include <iostream>
#include "Bot.h"
#include "actionState.h"
#include "Charges0.h"
#include "Charges1.h"
#include "Charges2.h"
#include "Charges3.h"

using namespace std;

class StateAI : public Bot
{
private:
	actionState *NO_CHARGES;
	actionState *CHARGES_1;
	actionState *CHARGES_2;
	actionState *CHARGES_3;

public:
	actionState state;

	void pick(int botChoice);
	StateAI(){
		state = NO_CHARGES;
	}
};

#endif
