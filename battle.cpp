#include "battle.h"
#include <algorithm> 
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

Encounter getRandomEncounter(int difficulty, vector<Encounter>AllEncounters)
{
    vector<Encounter> shuffledVector = shuffleVector(AllEncounters);
    Encounter randEnc = randomEncounter(shuffledVector, difficulty);
    cout << "Randomly selected encounter: " << endl;
    cout << randEnc << endl;
    return randEnc;
}


vector<Encounter> shuffleVector(vector<Encounter>AllEncounters)
{
    
    //srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    random_shuffle(AllEncounters.begin(), AllEncounters.end());
    return AllEncounters;
}

Encounter randomEncounter(vector<Encounter>filteredVector, int difficulty)
{
    int i, j;
    vector<int> v1;
    for(Encounter en: filteredVector)
    {
        v1.push_back(en.getNumericValueForDifficulty());
    };
    vector<int> v2;
    v2.push_back(difficulty);
    vector<int>::iterator i1;
    i1 = std::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout << filteredVector[i1-v1.begin()] << endl;
    return filteredVector[i1-v1.begin()];
}


void battleEnv(Encounter randomEnc, vector<Individuals<Investigator>>& characters)
{
    cout << "" << endl;
    cout << "Enemies" << endl;
    for (Creature cre: randomEnc.creatures)
    {
        cout << cre << endl;
        cout << "Initive roll: "<<cre.getInitiative() << endl;
        cout << "" << endl;
    }
    cout << "" << endl;
    cout << "Characters" << endl;
    for (Individuals<Investigator> inv:  characters)
    {
        cout << inv.type << endl;
        cout << "Initive roll: " << inv.type.getInitiative() << endl;
        cout << "" << endl;
    }

};

vector<string> generateInitiveOrder(vector<Being> allCharacters)
{
    // We send everything in here and generate a string array;
    // the strings are of type <e/c><i> e = enemey c = character and <i> is the index in correct corresponding vect 
    vector<string>bla;
    return bla;

};

bool checkIfEncounterIsOver(vector<Investigator> &characters,  vector<Creature> &enemies)
{
    bool isItOver;
    return isItOver;

};

bool checkIfAllCharactersAreDead(vector<Investigator>& characters)
{
    bool areAllCharactersDead;
    return areAllCharactersDead;

};
bool checkIfAllEnemiesAreDead(Encounter enc)
{
    bool areAllEnemiesDead;
    return areAllEnemiesDead;
};

bool checkIfSingleEnemeyIsDead(Creature enemey)
{
    return true;
}

bool checkIfSingleCharacterIsDead(Investigator character)
{
    return true;
};