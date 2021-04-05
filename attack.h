#ifndef ATTACK_624885114
#define ATTACK_624885114
#include <iostream>
#include <vector>
#include "dice.h"

using namespace std;
class Attack
{
    public:
        Attack();
        Attack(string name, string proficiencyAbility, Dice dice, int amountOfDiceThrown);
        friend ostream& operator<<(ostream& out, const Attack a);

        string name, proficiencyAbility;
        Dice dice; 
        int amountOfDiceThrown;
        void printInfo();
};

void seeAllAttacks(vector<Attack> attacks);
Attack selectAttack(vector<Attack> attacks);
Attack createIndividualAttack (vector<Dice> allDice);

#endif