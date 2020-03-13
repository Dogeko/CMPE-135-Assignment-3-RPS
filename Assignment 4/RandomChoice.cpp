#include "RandomChoice.h"

void RandomChoice::pick(int playerChoice)
{
    choice = rand() % 3;
    setChoice(choice);
    if (choice == 0)
    {
        cout << "Your opponent picked Paper!" << endl;
    }
    else if (choice == 1)
    {
        cout << "Your opponent picked Scissors!" << endl;
    }
    else if (choice == 2)
    {
        cout << "Your opponent picked Rock!" << endl;
    }
}