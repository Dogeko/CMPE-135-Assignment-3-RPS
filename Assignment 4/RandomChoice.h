#ifndef RANDOMCHOICE_H
#define RANDOMCHOICE_H

#include <iostream>
#include "Bot.h"

using namespace std;

class RandomChoice : public Bot{
public:
    void pick(int playerChoice);
};

#endif