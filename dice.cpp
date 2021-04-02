#include "dice.h"
#include <random>
#include <iostream>
#include <chrono>

using namespace std;

Dice::Dice(string name, string nickname, int sides)
{
    this->name = name;
    this->nickname = nickname;
    this->sides = sides;
};

Dice::Dice() : Dice("mobius strip", "D1", 1){};

ostream& operator<<(ostream& out, const Dice d)
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