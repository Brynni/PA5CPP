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

void Weapon::AddAttacksToWeapon(vector <Attack> newAttacks){
    this->attacks = newAttacks;
}

void Weapon::AddAttackToWeapon(Attack newAttack){
    this->attacks.push_back(newAttack);
}

Weapon createIndividualWeapon ()
{
    string name;
    cout << "Enter name for the weapon: ";
    cin >> name;
    cout << endl;
    return Weapon(name);
};

void Weapon::printInfo()
{
    cout << this->name << endl;
}

void seeAllWeapons(vector<Weapon> weapons)
{
    cout << "WEAPONS: " << endl;
    int counter = 0;
    for (Weapon wp : weapons )
        {   
            counter ++;
            cout << counter << ". "; 
            wp.printInfo();
        }
};

Weapon selectWeapon(vector<Weapon> weapons)
{
    seeAllWeapons(weapons);
    int selection;
    cout << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    while (selection < 1 || selection > weapons.size())
    {
        cout << "Invalid selection! You must select a weapon between 1 and " << weapons.size() << endl; 
        cout << "Enter your selection: ";
        cin >> selection;
    }
    return weapons[selection -1];
}