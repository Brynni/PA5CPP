#ifndef BEING_12314123
#define BEING_12314123


#include <iostream>
using namespace std;


class Being
{
    public:
        Being();
        Being(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma);
        friend ostream& operator<<(ostream& out, const Being b);
        string name;
        int life, damage, currentLife, strength, intelligence, constitution, dexterity,  wisdom,  charisma;
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
        int getCurrentLife();
        string getName();



};

#endif