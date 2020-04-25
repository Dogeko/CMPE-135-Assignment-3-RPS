#ifndef CHARGES1_H
#define CHARGES1_H

#include <iostream>
#include "Bot.h"
#include "actionState.h"
using namespace std;

class Charges1 : public actionState
{
public:
	void pick(int botChoice);
};

#endif
