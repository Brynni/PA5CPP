#include "attack.h"
#include "being.h"
#include <random>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

Being::Being(string name, int life, int strength, int intelligence, int dexterity, int constitution, int wisdom, int charisma)
{   
    std::vector <Attack> attacks;
    this->name = name;
    this->life = life;
    this->currentLife = life;
    this->strength = strength;
    this->intelligence = intelligence;
    this->dexterity = dexterity;
    this->constitution = constitution;
    this->wisdom= wisdom;
    this->charisma = charisma;
    this->attacks = attacks;
    this->weapons = weapons;

};

// Should be replaced with random values from 0-10 
Being::Being() : Being ("being", 5,5,5,5,5,5,5){};


ostream& operator<<(ostream& out, const Being b)
{
    out << "Being\n";
    out << "Max Life: " << b.life << endl;
    out << "Current life: " << b.currentLife << endl;
    out << "Strength: " << b.strength << endl;
    out << "Intelligence: " << b.intelligence << endl;
    out << "Dexterity: " << b.dexterity << endl;
    out << "Constitution: " << b.constitution << endl;
    out << "Wisdom: " << b.wisdom << endl;
    out << "Charisma: " << b.charisma;
    return out;
}

void Being::takeDamage(int attackDamage)
{
    int newCurrentHealth;
    
    cout << name << " took " << attackDamage << " points of damage!" << endl;
    if ((currentLife - attackDamage) < 0)
    {
        damage = life;
        newCurrentHealth = 0;
    } else {
        newCurrentHealth = currentLife - attackDamage;
    }
    
    cout << name << "'s health points are now currently " << newCurrentHealth << endl;
    if (currentLife == 0){
        cout << name << " is dead!";
    }
    
    this->currentLife = newCurrentHealth;
}

void Being::healDamage(int healingPoints)
{   
    
    if ((currentLife + healingPoints) < life)
    {
        cout << name << " has been healed for " << healingPoints << " points!" << endl;
        this->currentLife = currentLife + healingPoints;
        cout << name << "'s current life is now " << currentLife << endl;
    } else{
        cout << name << " is now fully healed! " << endl;
        this->currentLife = life;
    }
}

void Being::updateLife()
{
    int newLife;
    cout << "Enter new life: " ;
    cin >> newLife;

    while(newLife > 10 || newLife < 0)
    {
        cout << "Please enter a valid life, the range is 0 -10" << endl;
        cin >> newLife;
    }
    this->life = newLife;

}

void Being::updateStrength()
{
   
    int newStrength;
    cout << "Enter new strength: " ;
    cin >> newStrength;

    while(newStrength > 30 || newStrength < 0)
    {
        cout << "Please enter a valid strength, the range is 1-30" << endl;
        cin >> newStrength;
    }
    this->strength = newStrength;

}

void Being::updateInt()
{
   
    int newInt;
    cout << "Enter new Intelligence : " ;
    cin >> newInt;

    while(newInt > 10 || newInt < 0)
    {
        cout << "Please enter a valid Intelligence, the range is 0 -10" << endl;
        cin >> newInt;
    }
    this->intelligence = newInt;

}

const string Being::getName()
{
    return this->name;
}

int Being:: getLife()
{
    return this->life;
}

int Being ::getStrength()
{
    return this->strength;
};

int Being::getInt()
{
    return this->intelligence;
}

int Being::getDex()
{
    return this->dexterity;
}

int Being::getCon()
{
    return this->constitution;
}

int Being::getCha()
{
    return this->charisma;
}

int Being::getWis()
{
    return this->wisdom;
}

int Being::getCurrentLife()
{
    return this->currentLife;
}

void Being::AddAttackToBeing(Attack attack){
    this->attacks.push_back(attack);
}

void Being::AddWeaponToBeing(Weapon weapon)
{
    this->weapons.push_back(weapon);
}

void Being::printAttacks(){
    cout << "_____________UNARMED ATTACKS_____________" << endl;
    for (int i=0; i < attacks.size(); i++)
    {
        cout << attacks[i];
    }
    cout << "_________________WEAPONS________________" << endl; 
    for (int j=0; j < weapons.size(); j++)
    {
        cout << weapons[j];
    }
}

int Being::getInitiative()
{
    int modifier = floor(this->dexterity /2 -5);
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % 20;
    return modifier + randNum + 1;

}