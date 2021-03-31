#ifndef WEAPON_624885114
#define WEAPON_624885114

#include <iostream>
using namespace std;

class Weapon
{
    public:
        Weapon(string name, string type, string modifier, int sides, int bonuses);
        friend ostream& operator<<(ostream& out, const Weapon w);

        int rollAttack();
        string getName();
        string getType();
        // does it use dex or str
        string getModifier();
        int getSides();
        // Bonuses to a roll 2d+x the x is usually the PC's modifier
        int getBonuses();

        string name;
        string type;
        int sides;
        int bonuses;
};





#endif