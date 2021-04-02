#ifndef ATTACK_624885114
#define ATTACK_624885114
#include <iostream>
using namespace std;
#include "dice.h"

class Attack
{
    public:
        Attack();
        Attack(string name, string proficiencyAbility, Dice dice, int amountOfDiceThrown);
        friend ostream& operator<<(ostream& out, const Attack a);

        string name, proficiencyAbility;
        Dice dice; 
        int amountOfDiceThrown;
};

#endif