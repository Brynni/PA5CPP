#include "battle.h"
#include <algorithm> 
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;

Encounter getRandomEncounter(int difficulty, const vector<Encounter>&AllEncounters)
{
    vector<Encounter> shuffledVector = shuffleVector(AllEncounters);
    Encounter randEnc = randomEncounter(shuffledVector, difficulty);
    cout << "Randomly selected encounter: " << endl;
    cout << randEnc << endl;
    return randEnc;
}


vector<Encounter> shuffleVector(vector<Encounter>AllEncounters)
{
    
    //srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    random_shuffle(AllEncounters.begin(), AllEncounters.end());
    return AllEncounters;
}

Encounter randomEncounter(vector<Encounter>filteredVector, int difficulty)
{
    int i, j;
    vector<int> v1;
    for(Encounter en: filteredVector)
    {
        v1.push_back(en.getNumericValueForDifficulty());
    };
    vector<int> v2;
    v2.push_back(difficulty);
    vector<int>::iterator i1;
    i1 = std::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout << filteredVector[i1-v1.begin()] << endl;
    return filteredVector[i1-v1.begin()];
}


void battleEnv(Encounter randomEnc, vector<Individuals<Investigator>>& characters)
{
    // cout << "Printing Character Attacks!" << endl;
    // for (Individuals<Investigator> inv : characters)
    // {
        
    //     inv.type.printAttacks();
    // }

    // cout << "Printing Enemy Attacks!" << endl;
    // for (Creature c : randomEnc.creatures)
    // {
    //     c.printAttacks();
    // }


    // cout << "Before BONGO Sort! " << endl;
    // for (int i = 0; i < characters.size();i++)
    // {
    //     cout << characters[i].type; 
    // }

    sort(characters.begin(), characters.end(), [](const Individuals<Investigator>& begin, const Individuals<Investigator>& end)
    {
        return begin.type.initiativeRoll > end.type.initiativeRoll;
    });

    
    
    // cout << "After Sort! " << endl;
    // for (int i = 0; i < characters.size();i++)
    // {
    //     cout << characters[i].type; 
    // }

    // cout << "Before BONGO Sort 2! " << endl;
    // for (int i = 0; i < randomEnc.creatures.size();i++)
    // {
    //     cout << randomEnc.creatures[i];
    //     cout << endl; 
    // }

    sort(randomEnc.creatures.begin(), randomEnc.creatures.end(), [](const Creature& begin, const Creature& end)
    {
        return begin.initiativeRoll > end.initiativeRoll;
    });
    
    
    cout << "After Sort 2! " << endl;
    for (int i = 0; i < randomEnc.creatures.size();i++)
    {
        cout << randomEnc.creatures[i];
        cout << randomEnc.creatures[i].attackOrder; 
        cout << endl;
    }
    
    
    
    cout << "Giving attack order!" << endl;
    int countOfAlreadyGivenOrder = 0;
    int i = 0;
    int j = 0;
    while (countOfAlreadyGivenOrder != randomEnc.creatures.size() + characters.size())
    {
        if (i < randomEnc.creatures.size() && randomEnc.creatures[i].getInitiative() > characters[j].type.getInitiative())
        {
            randomEnc.creatures[i].updateAttackOrder(countOfAlreadyGivenOrder);
            i++;
            countOfAlreadyGivenOrder++;
        } 
        else if (j < characters.size()){
            characters[j].type.updateAttackOrder(countOfAlreadyGivenOrder);
            j++;
            countOfAlreadyGivenOrder++;
        }
        else if(j == characters.size()){
            randomEnc.creatures[i].updateAttackOrder(countOfAlreadyGivenOrder);
            i++;
            countOfAlreadyGivenOrder++;
        }
        
    }

    sort(characters.begin(), characters.end(), [](const Individuals<Investigator>& begin, const Individuals<Investigator>& end)
    {
        return begin.type.attackOrder < end.type.attackOrder;
    });

    sort(randomEnc.creatures.begin(), randomEnc.creatures.end(), [](const Creature& begin, const Creature& end)
    {
        return begin.attackOrder < end.attackOrder;
    });

    for (Creature cre: randomEnc.creatures)
    {
        Creature beast = createCreature(cre);
        cout << "Name: " <<cre.getName() <<  " Attack order: " << cre.attackOrder << " Initiative roll: "<<cre.getInitiative()<< endl;
    }
    cout << "" << endl;
    cout << "Characters" << endl;
    for (Individuals<Investigator> inv:  characters)
    {
        cout << "Name: " << inv.type.getName() << " Attack order: " << inv.type.attackOrder << " Initiative roll: " << inv.type.getInitiative() << endl;
    }

    //cout << "The amount of creatures:  " << countOfAlreadyGivenOrder << endl;
    //cout << "Starting the battle itself" << endl;
    for (Creature cre: randomEnc.creatures)
    {
        
    }
    bool encounterIsFinished = false;
    while (encounterIsFinished == false)
    {
        //cout << "in the while loop!" << endl;
        int currentOrder = 0;
        int attackSelect;
        int i = 0;
        int j = 0;
        for (i, j; currentOrder + 1 < countOfAlreadyGivenOrder;)
        {
        cout <<"creature size" <<randomEnc.creatures.size() << endl;
        cout << "creature[i] attackorder  "<<randomEnc.creatures[i].getAttackOrder() << endl;
        cout << "current Order " <<currentOrder << endl;
        {
            
            if(i < randomEnc.creatures.size() && randomEnc.creatures[i].getAttackOrder()  ==currentOrder)
            {
                
                currentOrder++;
                cout <<randomEnc.creatures[i].attacks.size() << endl;
                //cout << "This freezes" << endl;
                cout << "Currently attacking:  " << randomEnc.creatures[i].getName() << endl;
                if (randomEnc.creatures[i].attacks.size() > 0){
                    // randomEnc.creatures[i].printCompactAttacks();
                    // cout << "Please enter attack selection: ";
                    // cin >> attackSelect;
                    // Attack selectedAttack;
                    // // Fáum 3 hér fyrir slash
                    // // Check the size
                    // cout << "my attack selection: " << attackSelect << endl;
                    // cout << "The characters amount of attacks! " <<randomEnc.creatures[i].attacks.size() << endl;
                    // // skilar 2 sem er stærðin af attacks
                    // if (attackSelect > 0)
                    // // fer hingað inn 
                    // {
                    //     bool foundAttack = false;
                    //     // attackselect = 3 > 2
                    //     if (attackSelect > randomEnc.creatures[i].attacks.size())
                    //     {
                    //         while (foundAttack == false) 
                    //         {

                    //             int newAttackSelect;
                    //             // Fáum 2
                    //             cout << "Here we should be selecting weapons size of weapons: " << randomEnc.creatures[i].weapons.size() << endl; 
                    //             // 3 hérna
                    //             cout << "this is the attack select b4 the deduction: " << attackSelect << endl;
                    //             // If this condition is met then we are working with a attack
                    //             // so attackSelect should be deducted from the size of the attacks vector
                    //             // Fáum 3 -2 = 1
                    //             newAttackSelect = attackSelect - randomEnc.creatures[i].attacks.size();
                    //             // 1
                    //             cout << "this is the attack select after the deduction: " << newAttackSelect << endl;
                    //             // AC = 2
                    //             int attackCounter = 0 + randomEnc.creatures[i].attacks.size();
                    //             // 1
                    //             cout << "Blah! the selected attack! "<< newAttackSelect << endl;
                    //             // 3
                    //             cout << "size of weapon attacks blah" << randomEnc.creatures[i].weapons.size() << endl;
                    //             for (int b = 0; b < randomEnc.creatures[i].weapons.size(); b++)
                    //             {
                    //                 // Wep.size = 2?
                    //                 for (int z = 0; z< randomEnc.creatures[i].weapons[b].attacks.size();z++)
                    //                 {
                    //                     // AC = 3?   
                    //                     attackCounter++;
                    //                     cout << "Current count: " << attackCounter << endl;
                    //                     // Ef að 
                    //                     if (attackCounter == newAttackSelect+1)
                    //                     {
                    //                         cout << "found my attacks!" << endl; 
                    //                         selectedAttack = randomEnc.creatures[i].weapons[b].attacks[z];
                    //                         cout <<  randomEnc.creatures[i].weapons[b].attacks[z]<< endl;
                    //                         foundAttack = true;
                    //                     }
                    //                 }
                    //             }
                    //             if (foundAttack == false)
                    //             {
                    //                 cout << "Error! Selection outside of range!" << endl;
                    //                 system("pause");
                    //                 randomEnc.creatures[i].printCompactAttacks();
                    //                 cout << "Enter your attack selection: ";

                    //                 cin >> attackSelect;
                    //             }
                    //         }
                    //     } else{
                    //         cout << selectedAttack << endl;
                    //         cout << "Does it go in here??" << endl;
                    //         Attack selectedAttack = characters[j].type.attacks[attackSelect-1];
                    //     }

                        Attack selectedAttack;
                        int unarmedOrWeapon;
                        cout << "Currently Attacking " << randomEnc.creatures[i].getName() << endl;
                        cout << "Do you want to make a weapon attack or a unarmed attack?" << endl;
                        cout << "1. Weapon attack" << endl;
                        cout << "2. Unarmed attack" << endl;
                        cin >> unarmedOrWeapon;
                        while(unarmedOrWeapon < 1 || unarmedOrWeapon > 2)
                        {
                            cout << "INVALID SELECTION" << endl;
                            cout << "Do you want to make a weapon attack or a unarmed attack?" << endl;
                            cout << "1. Weapon attack" << endl;
                            cout << "2. Unarmed attack" << endl;
                        }

                        if (unarmedOrWeapon == 1)
                        {
                            // Select the weapon here
                            int weaponSelection;
                            int weaponSize = randomEnc.creatures[i].weapons.size();
                            randomEnc.creatures[i].printOnlyWeapons();
                            cout << "Select your weapon: ";
                            cin >> weaponSelection;
                            while (weaponSelection < 0 || weaponSelection > weaponSize)
                            {
                                cout << "Invalid selection: " << endl;
                                randomEnc.creatures[i].printOnlyWeapons();
                                cout << "Select your weapon: ";
                                cin >> weaponSelection;
                                cout << " " << endl;
                            }


                            int attackSelection;
                            int attackSize = randomEnc.creatures[i].weapons[weaponSelection-1].attacks.size();
                            int a_counter = 0;
                            // Iterating the attacks
                            for (Attack a : randomEnc.creatures[i].weapons[weaponSelection-1].attacks)
                            {
                                a_counter ++;
                                a.printInfo();
                            }
                            cout << "Select your attack: ";
                            cin >>attackSelection;
                            while (attackSelection < 0 || attackSelection > attackSize)
                            {
                                int a_counter = 0;
                                cout << "INVALID SELECTION!!!" << endl;
                                for (Attack a : randomEnc.creatures[i].weapons[weaponSelection-1].attacks)
                                {
                                    a_counter ++;
                                    a.printInfo();
                                }
                                cout << "Select your attack: ";
                                cin >>attackSelection;

                            }

                            selectedAttack = randomEnc.creatures[i].weapons[weaponSelection-1].attacks[attackSelection-1];
                                   
                        }

                        if(unarmedOrWeapon == 2)
                        {
                            int attackSelection;
                            int attackSize = randomEnc.creatures[i].attacks.size();
                            int a_counter = 0;
                            // Iterating the attacks
                            for (Attack a : randomEnc.creatures[i].attacks)
                            {
                                a_counter ++;
                                a.printInfo();
                            }
                            cout << "Select your attack: ";
                            cin >>attackSelection;
                            while (attackSelection < 0 || attackSelection > attackSize)
                            {
                                int a_counter = 0;
                                cout << "INVALID SELECTION!!!" << endl;
                                for (Attack a : randomEnc.creatures[i].attacks)
                                {
                                    a_counter ++;
                                    a.printInfo();
                                }
                                cout << "Select your attack: ";
                                cin >>attackSelection;

                            }

                            selectedAttack = randomEnc.creatures[i].attacks[attackSelection-1];
                        }





                        cout << selectedAttack;
                        //selectCreature(randomEnc.creatures).takeDamage(selectedAttack.outPutDamage());
                        /* cout << "Select a Person to attack!" << endl;
                        int selectedCreatureIndex;
                        cin >> selectedCreatureIndex;
                        //Attack selectedAttack = randomEnc.creatures[i].attacks[attackSelect-1]; */
                        selectIndividualInvestigator(characters).type.takeDamage(selectedAttack.outPutDamage());
                    } else {
                        cout << "Invalid selection!" << endl;
                    }
                } else {
                    cout << randomEnc.creatures[i].getName() << " has no attacks" << endl;
                }
                i++;
            }
            if(j < characters.size() && characters[j].type.getAttackOrder() ==currentOrder)
            {
                cout << "It is characters " << characters[j].type.getName() << " turn!" << endl;
                currentOrder++;
                if (characters[j].type.attacks.size() > 0) {
                    // characters[j].type.printCompactAttacks();
                    // cout << "Enter your attack selection: ";
                    // Attack selectedAttack;
                    // cin >> attackSelect;
                    // if (attackSelect > 0)
                    // {
                    //     bool foundAttack = false;
                    //     if (attackSelect > characters[j].type.attacks.size())
                    //     {
                    //         while (foundAttack == false) 
                    //         {
                    //             int newAttackSelect;
                    //             cout << "Here we should be selecting weapons size of weapons: " << characters[j].type.weapons.size() << endl; 
                    //             cout << "this is the attack select b4 the deduction: " << attackSelect << endl;
                    //             // If this condition is met then we are working with a attack
                    //             // so attackSelect should be deducted from the size of the attacks vector
                    //             newAttackSelect = attackSelect - characters[j].type.attacks.size();
                    //             cout << "this is the attack select after the deduction: " << newAttackSelect << endl;
                    //             int attackCounter = 0 + characters[j].type.attacks.size();
                    //             cout << "Blah! the selected attack! "<< newAttackSelect << endl;
                    //             for (int b = 0; b < characters[j].type.weapons.size(); b++)
                    //             {
                    //                 for (int z = 0; z< characters[j].type.weapons[b].attacks.size();z++)
                    //                 {   
                    //                     attackCounter++;
                    //                     cout << "Current count: " << attackCounter << endl;
                    //                     if (attackCounter == newAttackSelect+1)
                    //                     {
                    //                         cout << "found my attacks!" << endl; 
                    //                         selectedAttack = characters[j].type.weapons[b].attacks[z];
                    //                         cout <<  characters[j].type.weapons[b].attacks[z]<< endl;
                    //                         foundAttack = true;
                    //                     }
                    //                 }
                    //             }
                    //             if (foundAttack == false)
                    //             {
                    //                 cout << "Error! Selection outside of range!" << endl;
                    //                 system("pause");
                    //                 characters[j].type.printCompactAttacks();
                    //                 cout << "Enter your attack selection: ";

                    //                 cin >> attackSelect;
                    //             }
                    //         }
                    //     }
                    //     else{
                    //         cout << "Does it go in here??" << endl;
                    //         Attack selectedAttack = characters[j].type.attacks[attackSelect-1];
                    //     }

                        


                        Attack selectedAttack;
                        int unarmedOrWeapon;
                        cout << "Currently Attacking " << characters[j].type.getName() << endl;
                        cout << "Do you want to make a weapon attack or a unarmed attack?" << endl;
                        cout << "1. Weapon attack" << endl;
                        cout << "2. Unarmed attack" << endl;
                        cin >> unarmedOrWeapon;
                        while(unarmedOrWeapon < 1 || unarmedOrWeapon > 2)
                        {
                            cout << "INVALID SELECTION" << endl;
                            cout << "Do you want to make a weapon attack or a unarmed attack?" << endl;
                            cout << "1. Weapon attack" << endl;
                            cout << "2. Unarmed attack" << endl;
                        }

                        if (unarmedOrWeapon == 1)
                        {
                            // Select the weapon here
                            int weaponSelection;
                            int weaponSize = characters[j].type.weapons.size();
                            characters[j].type.printOnlyWeapons();
                            cout << "Select your weapon: ";
                            cin >> weaponSelection;
                            while (weaponSelection < 0 || weaponSelection > weaponSize)
                            {
                                cout << "Invalid selection: " << endl;
                                characters[j].type.printOnlyWeapons();
                                cout << "Select your weapon: ";
                                cin >> weaponSelection;
                            }


                            int attackSelection;
                            int attackSize = characters[j].type.weapons[weaponSelection-1].attacks.size();
                            int a_counter = 0;
                            // Iterating the attacks
                            for (Attack a : characters[j].type.weapons[weaponSelection-1].attacks)
                            {
                                a_counter ++;
                                a.printInfo();
                            }
                            cout << "Select your attack: ";
                            cin >>attackSelection;
                            while (attackSelection < 0 || attackSelection > attackSize)
                            {
                                int a_counter = 0;
                                cout << "INVALID SELECTION!!!" << endl;
                                for (Attack a : characters[j].type.weapons[weaponSelection-1].attacks)
                                {
                                    a_counter ++;
                                    a.printInfo();
                                }
                                cout << "Select your attack: ";
                                cin >>attackSelection;

                            }

                            selectedAttack = characters[j].type.weapons[weaponSelection-1].attacks[attackSelection-1];
                                   
                        }
                        if (unarmedOrWeapon == 2)
                        {
                            int attackSelection;
                            int attackSize = characters[j].type.attacks.size();
                            int a_counter = 0;
                            // Iterating the attacks
                            for (Attack a : characters[j].type.attacks)
                            {
                                a_counter ++;
                                a.printInfo();
                            }
                            cout << "Select your attack: ";
                            cin >>attackSelection;
                            while (attackSelection < 0 || attackSelection > attackSize)
                            {
                                int a_counter = 0;
                                cout << "INVALID SELECTION!!!" << endl;
                                for (Attack a : characters[j].type.attacks)
                                {
                                    a_counter ++;
                                    a.printInfo();
                                }
                                cout << "Select your attack: ";
                                cin >>attackSelection;

                            }

                            selectedAttack = characters[j].type.attacks[attackSelection-1];
                        }
                        cout << selectedAttack;
                        //selectCreature(randomEnc.creatures).takeDamage(selectedAttack.outPutDamage());
                        cout << randomEnc;
                        cout << "Select a creature to attack!" << endl;
                        int selectedCreatureIndex;
                        cin >> selectedCreatureIndex;
                        randomEnc.creatures[selectedCreatureIndex].takeDamage(selectedAttack.outPutDamage());
                    } else {
                        cout << "Invalid selection!" << endl;
                    }
                    
                } else {
                    cout << "This human has no attacks" << endl;
                }
                j++;
            }
            
            if (checkIfEncounterIsOver(characters, randomEnc.creatures))
            {
                cout << "Battle is over!" << endl;
                encounterIsFinished = true;
                if(checkIfAllCharactersAreDead(characters))
                {
                    cout<< "You lost!!" << endl;
                    system("pause");
                }
                else
                {
                    cout << "VICTORY!!!!" << endl;
                    system("pause");
                }
            } 
        }
            
};

bool checkIfEncounterIsOver(vector<Individuals<Investigator>> &characters,  vector<Creature> &enemies)
{
    bool isItOver = false;
    if (checkIfAllCharactersAreDead(characters) || checkIfAllEnemiesAreDead(enemies))
    {
        isItOver = true;
    }
    return isItOver;

};

bool checkIfAllCharactersAreDead(vector<Individuals<Investigator>>& characters)
{
    bool areAllCharactersDead = false;
    int deadCharacterCount = 0;
    for (int i = 0; i < characters.size();i++)
    {
        if (characters[i].type.getCurrentLife()==0)
        {
            deadCharacterCount++;
        }
    }
    if (deadCharacterCount == characters.size())
    {
        areAllCharactersDead = true;        
    }
    return areAllCharactersDead;

};
bool checkIfAllEnemiesAreDead(vector <Creature>& creatures)
{
    bool areAllEnemiesDead=false;
    int deadCharacterCount = 0;
    for (int i = 0; i < creatures.size();i++)
    {
        if (creatures[i].getCurrentLife()<=0)
        {
            deadCharacterCount++;
        }
    }
    if (deadCharacterCount == creatures.size())
    {
        areAllEnemiesDead = true;        
    }
    return areAllEnemiesDead;
};

bool checkIfSingleEnemeyIsDead(Creature &enemey)
{
    if (enemey.getCurrentLife() <= 0)
    {
        return true;
    }

    return false;
}

bool checkIfSingleCharacterIsDead(Investigator &character)
{
        if (character.getCurrentLife() <= 0)
    {
        return true;
    }

    return false;
};