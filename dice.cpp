#include "dice.h"
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

Dice::Dice(const string &name, const string& nickname, int sides)
{
    this->name = name;
    this->nickname = nickname;
    this->sides = sides;
};

Dice::Dice() : Dice("mobius strip", "D1", 1){};

ostream& operator<<(ostream& out, const Dice &d)
{
    out << "Dice\n";
    out << "Name: " << d.name << endl;
    out << "Nickname: " << d.nickname << endl;
    out << "Amount of sides: " << d.sides;
    return out;
}

int Dice::rollDice()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % sides;
    return randNum + 1;
}

int Dice::getSides()
{
    return this->sides;
}

string Dice::getName()
{
    return this->name;
}

string Dice::getNickname()
{
    return this->nickname;
}

void initializeBaseDice( vector <Dice> &allDice)
{
    Dice d20( "ICOSAHEDRON", "D20", 20);
    Dice d12( "DODECAHEDRON", "D12", 12);
    Dice d10( "PENTAGONAL TRAPEZOHEDRON", "D10", 10);
    Dice d8( "OCTAHEDRON", "D8", 8);
    Dice d6("CUBE", "D6" , 6);
    Dice d4("TETRAHEDRON", "D4", 4);
    allDice.push_back(d20);
    allDice.push_back(d12);
    allDice.push_back(d10);
    allDice.push_back(d8);
    allDice.push_back(d6);
    allDice.push_back(d4);
};

void printIndividualDice(vector <Dice> allDice)
{
    int counter = 0;
    cout << "Printing all dice" << endl;
    for (Dice d: allDice)
    {
        counter ++;
        cout << counter << ". " << d.getName() <<"("<< d.getNickname() <<")" << " " << d.getSides() << endl;
    }
};

Dice selectIndividualDice(const vector <Dice> &allDice)
{
    printIndividualDice(allDice);
    cout << endl;
    int selection;
    cout << "Select what Dice you would like to roll: ";
    cin >> selection;
    while(selection < 1 || selection > allDice.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << allDice.size() << endl;
        cout << "Select what Dice you would like to roll: ";
        cin >> selection;
    }

    return allDice[selection -1];
}

Dice selectIndividualDiceByNickname(vector <Dice> allDice, const string& nickname)
{
    for (int i = 0; i < allDice.size(); i++)
    {
        if (allDice[i].getNickname() == nickname)
        {
            return allDice[i];
        }
    }
    return Dice();
    
}