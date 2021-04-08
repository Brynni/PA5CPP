#ifndef WEAPON_624885114
#define WEAPON_624885114

#include <iostream>
#include <vector>
#include "attack.h"
using namespace std;

class Weapon
{
    public:
        Weapon();
        Weapon(string name/* , string type, string modifier, int sides, int bonuses */);
        friend ostream& operator<<(ostream& out, const Weapon w);
        void printInfo();
        void AddAttacksToWeapon(vector <Attack> newAttacks);
        void AddAttackToWeapon(Attack newAttack);
        string getName();
        /* int rollAttack();
        
        string getType();
        // does it use dex or str
        string getModifier();
        int getSides();
        // Bonuses to a roll 2d+x the x is usually the PC's modifier
        int getBonuses(); */

        string name;
        /* string type;
        int sides;
        int bonuses; */
        vector <Attack> attacks;
};



void seeAllWeapons(vector<Weapon> weapons);
Weapon selectWeapon(vector<Weapon> weapons);
Weapon createIndividualWeapon ();
#endif