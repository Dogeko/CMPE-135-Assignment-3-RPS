#include "BotFactory.h"

Bot* BotFactory::pickAlgo(char algo_type)
{
	switch (algo_type)
	{
	case 'R':
		return new RandomAI();
	case 'S':
		return new StateAI();
	default:
		return NULL;
	}
}