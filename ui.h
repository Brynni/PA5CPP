#ifndef UI_624885114
#define UI_624885114
#include <iostream>
#include <vector>
#include <limits>
#include "creature.h"
#include "individuals.h"
using namespace std;

int renderMainMenu();
int uiCreatureOrHorror();
int uiRenderListOfType();
int uiDetailListOrCompactList();
int uiSelectCHP();
int uiBasicOrCustom();
int uiNPCOrPC();
int uiSelectNPCOrPC();
int uiPrintAllTypes ();
void printAllTypes();
int uiIndividualList();
int uiEditIndividuals();
int uiStatToEdit();
int uiAttackAdder();
int uiCreateAttack();
int uiCreateHuman();
int uiCreateEncounter(int size);
int uiEditEncounter();
int uiSelectOrRemoveFromEncounter();
int uiAddOrSaveRoster();
string uiSelectDifficulty();
void uiCreateIndividualCreature(vector <Creature> creatures, vector<Individuals<Creature>>IndividualsCreatures, string typeOfCreature);
int getNumberOfCreatures(vector<Individuals<Creature>>individualsCreatures, string name);
string uiSelectBeingType();
string uiUpdateStat();

#endif



