#include "encounter.h"
#include <iostream>

using namespace std;

Encounter::Encounter() : Encounter("Easy"){};

Encounter::Encounter(string difficulty)
{
    vector <Creature> creatures;
    this->difficulty = difficulty;
    this->creatures = creatures;
}

ostream& operator<<(ostream& out, const Encounter e)
{
    out << "______ENCOUNTER______\n";
    out << "Difficulty: " << e.difficulty << endl;
    out << "---Enemies---" << endl;
    Creature singleCreature;
    int counter = 0;
    for (int i = 0; i < e.creatures.size(); i++)
    {   
        counter++;
        singleCreature = e.creatures[i];
        out << counter << ". " << "Name: "<< singleCreature.getName() << " Hitpoints: " <<singleCreature.getCurrentLife() << "/" << singleCreature.getLife() << endl;
    }
    return out;
}

void Encounter::addEnemyToEncounter(Creature enemy){
    this->creatures.push_back(enemy);
}

void Encounter::changeDifficulty(string newDifficulty){
    this->difficulty = newDifficulty;
}

void Encounter::removeEnemyFromEncounter(int index){
    
    creatures.erase(creatures.begin()+index);
}

void Encounter::clearEncounter(){
    vector <Creature> creatures;
    this->creatures = creatures;
};

int Encounter::getNumericValueForDifficulty(){
    int retVal;
    if (this->difficulty == "Easy")
    {
        retVal = 0;
    }
    if (this->difficulty == "Medium")
    {
        retVal = 1;
    }
    if (this->difficulty == "Hard")
    {
        retVal = 2;
    }
    if (this->difficulty == "Impossible")
    {
        retVal = 3;
    }

    return retVal;
}