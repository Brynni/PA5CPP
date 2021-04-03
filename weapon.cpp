#include "attack.h"
#include "weapon.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Weapon::Weapon(string name/* , string type, string modifier, int sides, int bonuses */)
{   
    vector <Attack> attacks;
    this->name = name;
    this->attacks = attacks;
}

ostream& operator<<(ostream& out, const Weapon w)
{
    out << "_________"+ w.name + " attacks___________" << endl;
    int i = 0;
    for (i ;i < w.attacks.size(); i++)
    {
        cout << w.attacks[i];
    }
    if (i == 0)
    {
        cout << "Error! No attacks assigned!" << endl;
    }

    return out;
}

Weapon::Weapon() : Weapon("Sword"){};

void Weapon::AddAttackToWeapon(vector <Attack> newAttacks){
    this->attacks = newAttacks;
}

Weapon createIndividualWeapon ()
{
    string name;
    cout << "Enter name for the weapon: ";
    cin >> name;
    cout << endl;
    return Weapon(name);
};