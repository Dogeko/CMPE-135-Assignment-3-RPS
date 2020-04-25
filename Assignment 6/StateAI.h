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
		NO_CHARGES = new Charges0(this);
		CHARGES_1 = new Charges1(this);
	    CHARGES_2 = new Charges2(this);
	    CHARGES_3 = new Charges3(this);
	    state = NO_CHARGES;
	}

	void setState(actionState newState){

		state = newState;
	}

	actionState getNoChargeState(){

		return NO_CHARGES;
	}

	actionState getCharge1State(){

		return CHARGES_1;
	}
	actionState getCharges2State(){

		return CHARGES_2;
	}
	actionState getCharges3State(){

		return CHARGES_3;
	}

};

#endif
