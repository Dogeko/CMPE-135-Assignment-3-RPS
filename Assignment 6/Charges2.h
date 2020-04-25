#ifndef CHARGES2_H
#define CHARGES2_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
using namespace std;

class Charges2 : public actionState
{
public:
	void pick(int botChoice);
};

#endif
