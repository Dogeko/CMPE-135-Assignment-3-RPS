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
	cout << "1 = Paper, 2 = Scissors, 3 = Rock: ";
	cin >> choice;
	switch (choice)
	{
	case 1: 
		setChoice(0);
		break;
	case 2:
		setChoice(1);
		break;
	case 3:
		setChoice(2);
		break;
	default:
        playerPick();
		break;
	}
}