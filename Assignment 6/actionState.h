#ifndef ACTIONSTATE
#define ACTIONSTATE

#include <iostream>
using namespace std;

class actionState
{
private:
    final static int NO_CHARGES = 0;
    final static int CHARGES1 = 1;
    final static int CHARGES2 = 2;
    final static int CHARGES3 = 3;
    int state = NO_CHARGES;
public:
    void pick(int botChoice);
};

#endif