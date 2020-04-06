#include "BotFactory.h"
#include "SmartChoice.h"

Bot *BotFactory::pickAlgo(char choice)
{
    switch (choice)
    {
    case 'S':
        return new SmartChoice();
    default:
        return NULL;
    }
}
