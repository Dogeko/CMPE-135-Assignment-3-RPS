#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human
{
protected:
	int choice;
	int charges;
public:
	int getChoice();
	void setChoice(int value);
	void playerPick();
};

#endif
