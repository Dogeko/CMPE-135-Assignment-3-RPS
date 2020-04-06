#include "Database.h"

bool Database::recordChoice(int choice)
{
    bool fullSequence = false;
    for (int i = 0; i < 5; i++) // return after the array hit 5
    {
        if (i < 4)
        {
            if (previousChoice[i] == 3)
            {
                previousChoice[i] = choice;
                choice_record[i] = choice;
                break;
            }
//            else{
//                for(int j = 0; j<4; j++){
//                    previousChoice[j] = choice_record[j+1];
//                }
//            }
        }
        else
        {
                if(check){
                    for(int j = 0; j < 4; j++){
                        previousChoice[j] = choice_record[j+1];
                    }
                    previousChoice[i] = choice;
                    choice_record[i] = choice;
                    for(int j = 0; j < 4; j++){
                        choice_record[j] = previousChoice[j];
                    }
                }
                else{
                    previousChoice[i] = choice;
                    choice_record[i] = choice;
                    check = true;
                }
            fullSequence = true;
        }
    }
    return fullSequence;
}


string Database::sendSequence()
{
    string SequenceString;
    for (int i = 0; i < 5; i++)
    {
        SequenceString += to_string(previousChoice[i]);
        cout<<previousChoice[i];
    }
    cout<<"\n";
//    S
    return SequenceString;
}

bool Database::checkDataMap(string key){
    bool keyFound = true;

    if(dataMap.find(key) == dataMap.end()) keyFound = false;

    return keyFound;

}
int Database::searchDataMap(string key){
    int occurance = -1;

    if(checkDataMap(key)){
         occurance =  dataMap.at(key);
    }

    return occurance;
}

void Database::addSequence(string key, int value){

    dataMap[key] = value;

}

void Database::removeSequence(string key){

    dataMap.erase(key);
}
void Database::updateSequence(string key){

    dataMap.at(key) += 1;
    for(auto& i: dataMap){
        cout<<"Updated Sequence:" << i.first <<" ocurrance:"<< i.second<<endl;
    }
}
int Database::get_previous_choices(){
    return *previousChoice;
}
