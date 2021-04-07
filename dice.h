#ifndef DICE_624885114
#define DICE_624885114
#include <iostream>
#include <vector>
using namespace std;

class Dice
{
    public:
        Dice();
        Dice(const string & name, const string & nickname, int sides);
        friend ostream& operator<<(ostream& out, const Dice& d);
        
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
Dice selectIndividualDice(const vector <Dice>& allDice);
Dice selectIndividualDiceByNickname(vector <Dice> allDice, const string & nickname);
#endif