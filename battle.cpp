#include "battle.h"
#include <algorithm> 
#include <random>
#include <chrono>
using namespace std;

void searchForEncounter(int difficulty, vector<Encounter>AllEncounters)
{
    vector<Encounter> shuffledVector = shuffleVector(AllEncounters);
    Encounter randEnc = randomEncounter(shuffledVector, difficulty);
}


vector<Encounter> shuffleVector(vector<Encounter>AllEncounters)
{
    cout << "Encounters before shuffle:" << endl;
    for (Encounter en : AllEncounters)
    {
        cout << en << endl;
    }
    //srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    random_shuffle(AllEncounters.begin(), AllEncounters.end());

    cout << "Encounters after shuffle:" << endl;
    for (Encounter en : AllEncounters)
    {
        cout << en << endl;
    }

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

    if (i1 != v1.end()) {
        cout << "vector2 is present at index " << (i1 - v1.begin());
    } else {
        cout << "vector2 is not present in vector1";
    }

    cout <<(i1 -v1.begin()) << endl;
    cout << filteredVector[i1-v1.begin()] << endl;
    return filteredVector[i1-v1.begin()];

}
