#include "Bot.h"

int Bot::getChoice
{
	return choice;
}

void Bot::botPick(int value)
{
	switch (value)
	{
	case 1:
		break;
	case 2:
		charges = charges + 1;
		break;
	case 3:
		charges = charges - 1;
		break;
	case 4:
		charges = charges - 3;
		break;
	default:
		botPick();
		break;
	}
}