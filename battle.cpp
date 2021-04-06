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
    
    cout << "Before BONGO Sort! " << endl;
    for (int i = 0; i < characters.size();i++)
    {
        cout << characters[i].type; 
    }

    sort(characters.begin(), characters.end(), [](const Individuals<Investigator>& begin, const Individuals<Investigator>& end)
    {
        return begin.type.initiativeRoll > end.type.initiativeRoll;
    });
    
    cout << "After Sort! " << endl;
    for (int i = 0; i < characters.size();i++)
    {
        cout << characters[i].type; 
    }

    cout << "Before BONGO Sort 2! " << endl;
    for (int i = 0; i < randomEnc.creatures.size();i++)
    {
        cout << randomEnc.creatures[i]; 
    }

    sort(randomEnc.creatures.begin(), randomEnc.creatures.end(), [](const Creature& begin, const Creature& end)
    {
        return begin.initiativeRoll > end.initiativeRoll;
    });
    
    cout << "After Sort 2! " << endl;
    for (int i = 0; i < randomEnc.creatures.size();i++)
    {
        cout << randomEnc.creatures[i]; 
    }
    
    for (Creature cre: randomEnc.creatures)
    {
        Creature beast = createCreature(cre);
        cout << "Name: " <<cre.getName() <<" Initiative roll: "<<cre.getInitiative()<< endl;
    }
    cout << "" << endl;
    cout << "Characters" << endl;
    for (Individuals<Investigator> inv:  characters)
    {
        cout << "Name: " << inv.type.getName() << " Initiative roll: " << inv.type.getInitiative() << endl;
    }

    int countOfAlreadyGivenOrder = 0;
    int i = 0;
    int j = 0;
    while (countOfAlreadyGivenOrder != randomEnc.creatures.size() + characters.size())
    {
        if (randomEnc.creatures[i].getInitiative() > characters[j].type.getInitiative())
        {
            randomEnc.creatures[i].updateAttackOrder(countOfAlreadyGivenOrder);
            i++;
        } else {
            characters[j].type.updateAttackOrder(countOfAlreadyGivenOrder);
            j++;
        }
        countOfAlreadyGivenOrder++;
    }
};

vector<string> generateInitiveOrder(vector<Being> allCharacters)
{
    // We send everything in here and generate a string array;
    // the strings are of type <e/c><i> e = enemey c = character and <i> is the index in correct corresponding vect 
    vector<string>bla;
    //vector<Being*> initOrder;
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