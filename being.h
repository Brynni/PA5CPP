#ifndef BEING_12314123
#define BEING_12314123


#include <iostream>
#include <vector>
#include <cmath>
#include "attack.h"
#include "weapon.h"
#include "dice.h"
using namespace std;


class Being
{
    public:
        Being();
        Being(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma);
        friend ostream& operator<<(ostream& out, const Being b);
        string name;
        int life, damage, currentLife, strength, intelligence, constitution, dexterity,  wisdom,  charisma;
        int initiativeRoll, attackOrder;
        vector <Attack> attacks;
        vector <Weapon> weapons;

        void AddAttackToBeing(Attack attack);
        void AddWeaponToBeing(Weapon weapon);
        void takeDamage(int attackDamage);
        void healDamage(int healingPoints);
        void updateLife();
        void updateStrength();
        void updateInt();
        int getLife();
        int getStrength();
        int getInt();
        int getDex();
        int getCon();
        int getCha();
        int getWis();
        int getInitiative();
        int getCurrentLife();
        const string getName();
        void updateStat(string ability);
        void updateCon();
        void updateDex();
        void updateWis();
        void updateCha();
        void printAttacks();
        void updateAttackOrder(int orderInAttackOrder);
        int getAttackOrder();

       



};

#endif