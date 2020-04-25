#include "Charges2.h"

void Charges2::pick(int botChoice)
{
	int choice = rand() % 3; //return block, charge, or fireball

	//block = 0, charge = 1, fireball = 2

	if(choice == 1){
			AI->setState(AI->getCharges1State());

	}
	if(choice == 2){
			AI->setState(AI->getCharges3State());

	}
}
