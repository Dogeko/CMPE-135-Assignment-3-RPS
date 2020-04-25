#include "Charges1.h"

void Charges1::pick(int botChoice)
{
	int choice = rand() % 3; //randomly choose between block, fireball, or charge

	//block = 0, charge = 1, fireball = 2

	if(choice == 1){
		AI->setState(AI->getCharges0State());

	}
	if(choice == 2){
		AI->setState(AI->getCharges2State());

	}
}
