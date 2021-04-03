#ifndef ENCOUNTER_624885114
#define ENCOUNTER_624885114
#include <iostream>
#include <vector>
#include "creature.h"
using namespace std;

class Encounter
{
    public:
        Encounter();
        Encounter(string difficulty);
        string difficulty;
        vector <Creature> creatures;

        void addEnemyToEncounter(Creature enemy);
        void changeDifficulty(string newDifficulty);
        void removeEnemyFromEncounter(int index);
};

#endif