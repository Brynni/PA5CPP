#include "encounter.h"
#include <iostream>

using namespace std;

Encounter::Encounter() : Encounter("Easy"){};

Encounter::Encounter(string difficulty)
{
    vector <Creature> creatures;
    this->difficulty = difficulty;
    this->creatures = creatures;
    this->heroes = heroes; 
}

ostream& operator<<(ostream& out, const Encounter e)
{
    out << "______ENCOUNTER______\n";
    out << "Difficulty: " << e.difficulty << endl;
    
    Creature singleCreature;
    Investigator singleHero;
    int counter = 0;
    if (e.creatures.size() > 0)
    {
        out << "---Enemies---" << endl;
        for (int i = 0; i < e.creatures.size(); i++)
        {   
            singleCreature = e.creatures[i];
            out << counter << ". " << "Name: "<< singleCreature.getName() << " Hitpoints: " <<singleCreature.getCurrentLife() << "/" << singleCreature.getLife() << endl;
            counter++;
        }
    } else {
        out << "----No Enemies In Encounter----" << endl;
    }
    
    return out;
}

void Encounter::addEnemyToEncounter(Creature enemy){
    this->creatures.push_back(enemy);
}

void Encounter::removeEnemyFromEncounter(int index){
    
    creatures.erase(creatures.begin()+index);
}

void Encounter::changeDifficulty(string newDifficulty){
    this->difficulty = newDifficulty;
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
void Encounter::printInfo()
{
    string encounter;
    for (int i = 0; i < this->creatures.size(); i++)
    {
        if (i==this->creatures.size()-1)
        {
            encounter += this->creatures[i].getName();
        } else {
            encounter += this->creatures[i].getName() + ", ";
        }
        
    }
    encounter += "(" + this->difficulty + ")\n";
    cout << encounter;

}

void seeAllEncounters(vector<Encounter> encounters)
{
    cout << "______List Of Encounters______" << endl;
    int counter = 0;
    for (Encounter enc : encounters )
        {   
            counter ++;
            cout << counter << ". "; 
            enc.printInfo();
        }
};