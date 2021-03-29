#ifndef BEING_12314123
#define BEING_12314123


#include <iostream>
using namespace std;


class Being
{
    public:
        Being();
        Being(int life, int strength, int intelligence);
        friend ostream& operator<<(ostream& out, const Being b);
        int life;
        int strength;
        int intelligence;
        void updateLife();
        void updateStrength();
        void updateInt();
        int getLife();
        int getStrength();
        int getInt();



};

#endif