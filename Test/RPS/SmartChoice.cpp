#include "SmartChoice.h"

void SmartChoice::pick(int playerChoice)
{
    int temp[5] = {};
    string search_paper;
    string search_scissor;
    string search_rock;
    int occurance_paper;
    int occurance_scissor;
    int occurance_rock;
    int smart_prediction = -1;
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
//        cout<<"using smart ml algo"<<endl;
//        choice = rand() % 3;
        *smart_choice = records.get_previous_choices();
        for(int i = 0; i<4;i++){
            temp[i] = smart_choice[i];
        }
        // paper 0
        temp[4] = 0;
        for (int i = 0; i < 5; i++)
        {
            search_paper += to_string(temp[i]);
        }
        // scissors 1
        temp[4] = 1;
        for (int i = 0; i < 5; i++)
        {
            search_scissor += to_string(temp[i]);
        }
        // rock 2
        temp[4] = 2;
        for (int i = 0; i < 5; i++)
        {
            search_rock += to_string(temp[i]);
        }
        occurance_paper = records.searchDataMap(search_paper);
        occurance_scissor = records.searchDataMap(search_scissor);
        occurance_rock = records.searchDataMap(search_rock);
        //

        if(occurance_paper > occurance_scissor){
            if(occurance_paper > occurance_rock){
                smart_prediction = 1; // robot picks scissors
            } else if (occurance_paper > occurance_rock){
                smart_prediction = 0;
            }
            else{
                smart_prediction = random()%3;// robot picks paper
            }
        }
    else if(occurance_scissor > occurance_paper){
        if(occurance_scissor > occurance_rock){
            smart_prediction = 2;// robot picks rock
        }else if(occurance_scissor < occurance_rock){
            smart_prediction = 0; // robot picks paper
        }
        else{
            smart_prediction = random()%3;
        }
    }
    else if(occurance_rock > occurance_paper){
        if(occurance_rock > occurance_scissor){
            smart_prediction = 0;// robot picks rock
        }else if(occurance_rock < occurance_scissor){
            smart_prediction = 2; // robot picks paper
        }
        else{
            smart_prediction = random()%3;
        }
    }else{
        smart_prediction = random()%3;
    }

        choice = smart_prediction;
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
