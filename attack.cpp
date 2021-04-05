#include "attack.h"
#include "dice.h"
#include <random>
#include <iostream>


using namespace std;

Attack::Attack(string name, string proficiencyAbility, Dice dice, int amountOfDiceThrown)
{   
    this->name = name;
    this->proficiencyAbility = proficiencyAbility;
    this->dice = dice;
    this->amountOfDiceThrown = amountOfDiceThrown;
};

ostream& operator<<(ostream& out, const Attack a)
{
    out << "|" << a.name << "|" << endl;
    out << "Lowest possible damage: 1 Highest possible damage " << a.dice.sides * a.amountOfDiceThrown << endl; 
    out << "Proficiency bonus granted for " << a.proficiencyAbility << endl;
    return out;
}

Attack::Attack() : Attack("punch","Strength", Dice(), 1){};

Attack createIndividualAttack (vector<Dice> allDice)
{
    string name, proficiencyAbbility; 
    Dice dice;
    int amountOfDiceThrown;
    int profSelector;
    string modifiers[6] = {"Strength", "Dexterity", "Wisdom", "Constitution", "Charisma", "Intelligence"};

    cout << "Enter name for the attack / spell attack:" << endl;
    cin >> name;
    for (int i = 0; i < 6; i++)
    {
        cout << i+1 <<".\t"<<modifiers[i] << endl;
    }
    
    cin >> profSelector;
    while (profSelector < 1 || profSelector > 6 ){
        cout << "You need to select a modifer" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << i+1 <<".\t"<<modifiers[i] << endl;
        }
        cin >> profSelector;
    }



    dice = selectIndividualDice(allDice);

    cout << "How many dices would you like to throw? " << endl;
    cout << "Enter choice here: ";
    cin >> amountOfDiceThrown;

    return Attack(name, modifiers[profSelector-1], dice, amountOfDiceThrown); 
};


void Attack::printInfo()
{
    cout << this->name << endl;
}

void seeAllAttacks(vector<Attack> attacks)
{
    cout << "ATTACKS- " << endl;
    int counter = 0;
    for (Attack atck : attacks )
        {   
            counter ++;
            cout << counter << ". "; 
            atck.printInfo();
        }
};

Attack selectAttack(vector<Attack> attacks)
{
    seeAllAttacks(attacks);
    int selection;
    cout << endl;
    cout << "Enter your selection: ";
    cin >> selection;

    while (selection < 1 || selection > attacks.size())
    {
        cout << "Invalid selection! You must select an attack between 1 and " << attacks.size() << endl; 
        cout << "Enter your selection: ";
        cin >> selection;
    }
    return attacks[selection -1];
}