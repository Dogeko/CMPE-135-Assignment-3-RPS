#include "Charges0.h"

void Charges0::pick(int botChoice)
{
	int choice = rand() % 2; //pick between charge or block

	//block = 0, charge = 1, fireball = 2

	if(choice == 1){
		AI.setState(AI.getCharges1State());

	}

}
