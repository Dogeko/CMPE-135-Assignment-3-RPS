#include "Human.h"

int Human::getChoice()
{
	return choice;
}

void Human::setChoice(int value)
{
	choice = value;
}

void Human::playerPick()
{
	cout << "1 = Charge, 2 = Block, 3 = Fireball ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		setChoice(0);
		charges = charges+1;
		break;
	case 2:
		setChoice(1);
		break;
	case 3:
		setChoice(2);
		charges = charges - 1;
		break;
	case 4:
		setChoice(4);
		cout<<"Karate Chop unlocked \n"<<endl;
		break;
	default:
        playerPick();
		break;
	}
}
