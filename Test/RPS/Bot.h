#ifndef BOT_H
#define BOT_H

#include <iostream>
using namespace std;

class Bot
{
protected:
	int choice;

public:
	int getChoice();
	void setChoice(int value);
	virtual void pick(int );
};

#endif
