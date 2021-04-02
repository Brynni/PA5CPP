#include "attack.h"
#include "dice.h"
#include <random>
#include <iostream>

using namespace std;

Attack::Attack(string name, string proficiencyAbility, Dice dice, int amountOfDiceThrown)
{   
    this->name = name;
    this->proficiencyAbility = proficiencyAbility;
    this->dice = dice;
    this->amountOfDiceThrown = amountOfDiceThrown;
};

ostream& operator<<(ostream& out, const Attack a)
{
    out << "|" << a.name << "|" << endl;
    out << "Lowest possible damage: 1 Highest possible damage " << a.dice.sides * a.amountOfDiceThrown << endl; 
    out << "Proficiency bonus granted for " << a.proficiencyAbility << endl;
    return out;
}

Attack::Attack() : Attack("punch","Strength", Dice(), 1){};