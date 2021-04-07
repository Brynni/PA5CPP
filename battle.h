#include "encounter.h"
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include "being.h"
#include "individuals.h"
#include "investigator.h"
#include "creature.h"
#include <string>
using namespace std;


Encounter getRandomEncounter(int difficultyLevel, const vector<Encounter> &AllEncounters);
vector<Encounter> shuffleVector(vector<Encounter>AllEncounters);
Encounter randomEncounter(vector<Encounter>filteredVector, int difficultyLevel);
void battleEnv(Encounter randomEnc, vector<Individuals<Investigator>> &characters);
//vector<Being> generateInitiveOrder(const vector<Creature>&enemies, vector<Investigator>& characters );
bool checkIfEncounterIsOver(vector<Individuals<Investigator>>& characters, vector <Creature>& enemies);
bool checkIfAllCharactersAreDead(vector<Individuals<Investigator>>& characters);
bool checkIfAllEnemiesAreDead(vector <Creature>& enemies);
bool checkIfSingleEnemeyIsDead(const Creature &enemey);
bool checkIfSingleCharacterIsDead(const Investigator &character);

