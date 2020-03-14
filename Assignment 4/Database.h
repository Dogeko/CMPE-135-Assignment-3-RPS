#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <array>
#include <unordered_map>
#include <iostream>

using namespace std;

class Database
{
private:
    int previousChoice[5] = { 3, 3, 3, 3, 3 };
    int choice_record[5] = {3};
    string choices;
    bool check = false;
    unordered_map<string , int>dataMap;
    int recordCount = 0;
public:
    bool recordChoice(int choice);
    string sendSequence();
    bool checkDataMap(string key);
    int searchDataMap(string key);
    void addSequence(string key, int value);
    void removeSequence(string key);
    void updateSequence(string key);
    int get_previous_choices();

};

#endif