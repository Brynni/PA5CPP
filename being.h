#ifndef BEING_12314123
#define BEING_12314123


#include <iostream>
using namespace std;


class Being
{
    public:
        Being();
        Being(int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma);
        friend ostream& operator<<(ostream& out, const Being b);
        int life, strength, intelligence, constitution, dexterity,  wisdom,  charisma;
        void updateLife();
        void updateStrength();
        void updateInt();
        int getLife();
        int getStrength();
        int getInt();
        int getDex();
        int getConst();
        int getCharisma();
        int getWisdom();



};

#endif