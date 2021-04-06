#include "encounter.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "being.h"
#include "investigator.h"
#include "creature.h"
#include <string>
using namespace std;


Encounter getRandomEncounter(int difficultyLevel, vector<Encounter>AllEncounters);
vector<Encounter> shuffleVector(vector<Encounter>AllEncounters);
Encounter randomEncounter(vector<Encounter>filteredVector, int difficultyLevel);
void battleEnv(Encounter randomEnc, vector<Investigator> &characters);
vector<Being> generateInitiveOrder(vector<Creature>&enemies, vector<Investigator>& characters );
bool checkIfEncounterIsOver(vector<Investigator>& characters, Encounter enc);
bool checkIfAllCharactersAreDead(vector<Investigator>& characters);
bool checkIfAllEnemiesAreDead(Encounter enc);
bool checkIfSingleEnemeyIsDead(Creature enemey);
bool checkIfSingleCharacterIsDead(Creature enemey);

