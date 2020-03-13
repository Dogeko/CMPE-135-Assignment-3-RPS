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
    unordered_map<int, int>dataMap;
    int recordCount = 0;
public:
    bool recordChoice(int choice);
    int sendSequence();
    bool checkDataMap(int key);
    void addSequence(int key, int value);
    void removeSequence(int key);
    void updateSequence(int key);

};

#endif