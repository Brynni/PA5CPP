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

void Encounter::addEnemyToEncounter(Creature enemy){
    this->creatures.push_back(enemy);
}

void Encounter::changeDifficulty(string newDifficulty){
    this->difficulty = newDifficulty;
}

void Encounter::removeEnemyFromEncounter(int index){
    
    creatures.erase(creatures.begin()+index);
}