#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

class Human
{
protected:
	int choice;
public:
	int getChoice();
	void setChoice(int value);
	void playerPick();
};

#endif