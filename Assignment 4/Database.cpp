#include "Database.h"

bool Database::recordChoice(int choice)
{
    bool fullSequence = false;

    for (int i = 0; i < 5; i++)
    {
        if (i < 4)
        {
            if (previousChoice[i] == 3)
            {
                previousChoice[i] = choice;
                break;
            }
//            else
//            {
//                int temp[4];
//                for (int j = 1; j < 4; j++)
//                {
//                    temp[j - 1] = previousChoice[j];
//                }
//                for (int j = 0; j < 3; j++)
//                {
//                    previousChoice[j] = temp[j];
//                }
//                previousChoice[i] = choice;
//            }
        }
        else
        {
            previousChoice[i] = choice;
            fullSequence = true;
        }
    }
    return fullSequence;
}


int Database::sendSequence()
{
    string SequenceString;
    for (int i = 0; i < 5; i++)
    {
        SequenceString += to_string(previousChoice[i]);
        cout<<previousChoice[i];
    }

    int Sequence = stoi(SequenceString);
    return Sequence;
}

bool Database::checkDataMap(int key){
    bool keyFound = true;

    if(dataMap.find(key) == dataMap.end()) keyFound = false;

    return keyFound;

}

void Database::addSequence(int key, int value){

    dataMap[key] = value;
    for(auto& i: dataMap){
        cout<<"Added Sequence: " << i.first <<" ocurrance:"<< i.second<<endl;
    }
    
}

void Database::removeSequence(int key){

    dataMap.erase(key);
}
void Database::updateSequence(int key){

    dataMap.at(key) += 1;
    for(auto& i: dataMap){
        cout<<"Updated Sequence:" << i.first <<" ocurrance:"<< i.second<<endl;
    }


}
