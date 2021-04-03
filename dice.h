#ifndef DICE_624885114
#define DICE_624885114
#include <iostream>
#include <vector>
using namespace std;

class Dice
{
    public:
        Dice();
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

void initializeBaseDice(vector <Dice> &allDice);
void printIndividualDice(vector <Dice> allDice);
Dice selectIndividualDice(vector <Dice> allDice);
Dice selectIndividualDiceByNickname(vector <Dice> allDice, string nickname);
#endif