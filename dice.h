#ifndef DICE_624885114
#define DICE_624885114
#include <iostream>
using namespace std;

class Dice
{
    public:
        Dice(string name, string nickname, int sides);
        friend ostream& operator<<(ostream& out, const Dice d);
        
        int rollDice();
        string getName();
        string getNickname();
        int getSides();

        string name;
        string nickname;
        int sides;
};

#endif