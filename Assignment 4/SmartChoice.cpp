#include "SmartChoice.h"

void SmartChoice::pick(int playerChoice)
{

    if(records.recordChoice(playerChoice)){
        //if there is a full sequence

        cout<<"sequence found"<<endl;

        foundSequence = records.sendSequence();

        //if key not found add key to
        if(!records.checkDataMap(foundSequence)){

            cout<<"adding sequence"<<endl;
            records.addSequence(foundSequence, 1);

        }
            //if key is found increment value at key
        else{

            cout<<"updating sequence"<<endl;
            records.updateSequence(foundSequence);
        }

        //insert predictive code here
        //printing psuedo ml choice
        cout<<"using smart ml algo"<<endl;
        choice = rand() % 3;
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
        setChoice(choice);
        records.recordChoice(choice);

    }
    else{
        //if not a full sequence use random algorithm
        cout<<"using smart rand algo"<<endl;
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
        records.recordChoice(choice);

    }

}