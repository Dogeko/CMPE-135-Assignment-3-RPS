#ifndef GAMERECORD_H
#define GAMERECORD_H

#include <stdio>
#include <iostream>
using namespace std;

class GameRecord
{
private:

    int humanWins;
    int botWins;
    int Draws;

public:

   void printRecord();
   void recordHumanWin();
   void recordBotWin();
   void recordDraw();

};

#endif
