#include "encounter.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "being.h"
using namespace std;


void searchForEncounter(int difficultyLevel, vector<Encounter>AllEncounters);
vector<Encounter> shuffleVector(vector<Encounter>AllEncounters);
Encounter randomEncounter(vector<Encounter>filteredVector, int difficultyLevel);

