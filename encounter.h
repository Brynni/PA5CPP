#ifndef ENCOUNTER_624885114
#define ENCOUNTER_624885114
#include <iostream>
#include <vector>
#include "creature.h"
#include "investigator.h"
using namespace std;

class Encounter
{
    public:
        Encounter();
        Encounter(string difficulty);
        string difficulty;
        vector <Creature> creatures;
        vector <Investigator> heroes;
        friend ostream& operator<<(ostream& out, const Encounter e);
        void addEnemyToEncounter(Creature enemy);
        void changeDifficulty(string newDifficulty);
        void removeEnemyFromEncounter(int index);
        void clearEncounter();
        int getNumericValueForDifficulty();
        void printInfo();
};

void seeAllEncounters(vector<Encounter> encounters);

#endif