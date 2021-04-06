#include "encounter.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "being.h"
#include "investigator.h"
using namespace std;


Encounter getRandomEncounter(int difficultyLevel, vector<Encounter>AllEncounters);
vector<Encounter> shuffleVector(vector<Encounter>AllEncounters);
Encounter randomEncounter(vector<Encounter>filteredVector, int difficultyLevel);
void battleEnv(Encounter randomEnc, vector<Investigator> characters);
int * generateInitiveOrder(Encounter randomEnc, vector<Investigator> characters );

