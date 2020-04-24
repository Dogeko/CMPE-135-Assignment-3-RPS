#ifndef BOT_H
#define BOT_H

#include <iostream>
using namespace std;

class Bot
{
protected:
	int charges;
public:
	int getChoice();
	void botPick(int value);
};

#endif