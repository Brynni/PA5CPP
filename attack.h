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
        Attack(const string &name, const string & proficiencyAbility, const Dice & dice, int amountOfDiceThrown);
        friend ostream& operator<<(ostream& out, const Attack & a);

        string name, proficiencyAbility;
        Dice dice; 
        int amountOfDiceThrown;
        void printInfo();
        int outPutDamage();
        void printCompactAttack();
        const string getName();
};

void seeAllAttacks(vector<Attack> attacks);
Attack selectAttack(vector<Attack> attacks);
Attack createIndividualAttack (const vector<Dice>& allDice);

#endif