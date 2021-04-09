#include "battle.h"
#include "dice.h"
#include <algorithm> 
#include <random>
#include <chrono>
#include <algorithm>
#include <math.h>
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
    sort(characters.begin(), characters.end(), [](const Individuals<Investigator>& begin, const Individuals<Investigator>& end)
    {
        return begin.type.initiativeRoll > end.type.initiativeRoll;
    });

    sort(randomEnc.creatures.begin(), randomEnc.creatures.end(), [](const Creature& begin, const Creature& end)
    {
        return begin.initiativeRoll > end.initiativeRoll;
    });
    
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

    bool encounterIsFinished = false;
    while (encounterIsFinished == false)
    {

        int currentOrder = 0;
        int attackSelect;
        int i = 0;
        int j = 0;
        for (i, j; currentOrder + 1 < countOfAlreadyGivenOrder;)
        {    
            if(i < randomEnc.creatures.size() && randomEnc.creatures[i].getAttackOrder()  ==currentOrder)
            {
                currentOrder++;
                cout <<randomEnc.creatures[i].attacks.size() << endl;
                cout << "Currently attacking:  " << randomEnc.creatures[i].getName() << endl;
                if (randomEnc.creatures[i].attacks.size() > 0 && randomEnc.creatures[i].getCurrentLife() > 0){
                    randomEnc.creatures[i].printCompactAttacks();
                    cout << "Please enter attack selection: ";
                    cin >> attackSelect;
                    Attack selectedAttack;
                    // Check the size
                    if (attackSelect > 0)
                    {
                        bool foundAttack = false;
                        if (attackSelect > randomEnc.creatures[i].attacks.size())
                        {
                            while (foundAttack == false) 
                            {
                                int newAttackSelect;
                                newAttackSelect = attackSelect - randomEnc.creatures[i].attacks.size();
                                int attackCounter = 0;
                                for (int b = 0; b < randomEnc.creatures[i].weapons.size(); b++)
                                {
                                    for (int z = 0; z< randomEnc.creatures[i].weapons[b].attacks.size();z++)
                                    {   
                                        attackCounter++;
                                        cout << "Current count: " << attackCounter << endl;
                                        if (attackCounter == newAttackSelect)
                                        {
                                            cout << "found my attacks!" << endl; 
                                            selectedAttack = randomEnc.creatures[i].weapons[b].attacks[z];
                                            cout <<  randomEnc.creatures[i].weapons[b].attacks[z]<< endl;
                                            foundAttack = true;
                                        }
                                    }
                                }

                                if (foundAttack == false)
                                {
                                    cout << "Error! Selection outside of range!" << endl;
                                    system("pause");
                                    randomEnc.creatures[i].printCompactAttacks();
                                    cout << "Enter your attack selection: ";

                                    cin >> attackSelect;
                                }
                            }
                        } 
                        
                        else
                        {
                            Attack selectedAttack = randomEnc.creatures[i].attacks[attackSelect-1];
                        }                        
                        cout << selectedAttack;
                        int selectedPersonIndex;                        
                        printIndividualInvestigator(characters);
                        cout << "Select a PC to attack!" << endl;
                        cin >> selectedPersonIndex;
                        while(selectedPersonIndex < 0 || selectedPersonIndex > characters.size())
                        {
                            cout << "INVALID SELECTION " << endl;
                            printIndividualInvestigator(characters);
                            cout << "Select a PC to attack!" << endl;
                            cin >> selectedPersonIndex;
                        }

                        int victimCon = characters[selectedPersonIndex-1].type.getCon();
                        int rollResult = rollD20();
                        cout << characters[selectedPersonIndex-1].type.getName() << " has Constitution of " << victimCon << endl;
                        cout << randomEnc.creatures[i].getName() << " Rolled : " << rollResult << endl;
                        if (rollResult >= victimCon)
                        {
                            cout << "A hit!!" << endl;
                            characters[selectedPersonIndex-1].type.takeDamage(selectedAttack.outPutDamage());
                        }

                        else
                        {
                            cout << "A Miss!!" << endl;
                        } 

                    } 
                    
                    else 
                    {
                        cout << "Invalid selection!" << endl;
                    }

                }

                else if (randomEnc.creatures[i].attacks.size() == 0)
                {
                    cout << randomEnc.creatures[i].getName() << " has no attacks" << endl;
                }

                else if (randomEnc.creatures[i].getCurrentLife() == 0)
                {
                    cout << randomEnc.creatures[i].getName() << " is dead..." << endl;
                }

                i++;
            }
            else if(j < characters.size() && characters[j].type.getAttackOrder() ==currentOrder )
            {
                cout << "It is characters " << characters[j].type.getName() << " turn!" << endl;
                currentOrder++;
                if (characters[j].type.attacks.size() > 0 && characters[j].type.getCurrentLife() > 0) {
                    characters[j].type.printCompactAttacks();
                    cout << "Enter your attack selection: ";
                    Attack selectedAttack;
                    cin >> attackSelect;
                    if (attackSelect > 0)
                    {
                        bool foundAttack = false;
                        if (attackSelect > characters[j].type.attacks.size())
                        {
                            while (foundAttack == false) 
                            {
                                int newAttackSelect;
                                newAttackSelect = attackSelect - characters[j].type.attacks.size();
                                int attackCounter = 0;
                                for (int b = 0; b < characters[j].type.weapons.size(); b++)
                                {
                                    for (int z = 0; z< characters[j].type.weapons[b].attacks.size();z++)
                                    {   
                                        attackCounter++;
                                        if (attackCounter == newAttackSelect)
                                        {
                                            selectedAttack = characters[j].type.weapons[b].attacks[z];
                                            cout <<  characters[j].type.weapons[b].attacks[z]<< endl;
                                            foundAttack = true;
                                        }
                                    }
                                }
                                if (foundAttack == false)
                                {
                                    cout << "Error! Selection outside of range!" << endl;
                                    system("pause");
                                    characters[j].type.printCompactAttacks();
                                    cout << "Enter your attack selection: ";

                                    cin >> attackSelect;
                                }
                            }
                        }

                        else
                        {
                            Attack selectedAttack = characters[j].type.attacks[attackSelect-1];
                        }
                        cout << selectedAttack;
                        int selectedCreatureIndex;
                        cout << randomEnc;
                        cout << "Select a creature to attack!" << endl;
                        
                        cin >> selectedCreatureIndex;
                        while (selectedCreatureIndex < 0 || selectedCreatureIndex > randomEnc.creatures.size()-1)
                        {
                            cout << "INVALID SELECTION" << endl;
                            cout << randomEnc;
                            cout << "Select a creature to attack!" << endl;
                        
                            cin >> selectedCreatureIndex;

                        }

                        
                        int victimCon = randomEnc.creatures[selectedCreatureIndex].getCon();
                        int rollResult = rollD20();
                        cout << randomEnc.creatures[selectedCreatureIndex].getName() << " has Constitution of " << victimCon << endl;
                        cout << characters[j].type.getName() << " Rolled : " << rollResult << endl;
                        if (rollResult >= victimCon)
                        {
                            cout << "A hit!!" << endl;
                            randomEnc.creatures[selectedCreatureIndex].takeDamage(selectedAttack.outPutDamage());
                        }

                        else
                        {
                            cout << "A Miss!!" << endl;
                        } 
                        
                    } 
                    
                    else 
                    {
                        cout << "Invalid selection!" << endl;
                    }
                    
                } 
                
                else if (characters[j].type.attacks.size() == 0) 
                {
                    cout << "This human has no attacks" << endl;
                }

                else if (characters[j].type.getCurrentLife() == 0)
                { 
                    cout << "this human is dead..." << endl;
                };

                j++;
            }
            
        if (checkIfEncounterIsOver(characters, randomEnc.creatures))
        {
            encounterIsFinished = true;
            if(checkIfAllCharactersAreDead(characters))
            {
                cout << "You lost :( " << endl;
                break;
            }

            if(checkIfAllEnemiesAreDead(randomEnc.creatures))
            {
                cout << "A GLORIOUS VICTORY " << endl;
                break;
            };
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

int rollD20()
{
    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));
    int randNum = rand() % 20;
    return randNum + 1;
}

int getAbilityModiferInvestigator(Attack a, Individuals<Investigator> & character)
{
    int profVal;
    if (a.proficiencyAbility == "Strength")
    {
        profVal = character.type.getStrength();
    }
    if (a.proficiencyAbility == "Intelligence")
    {
       profVal = character.type.getInt();
    }
    if (a.proficiencyAbility == "Constitution")
    {
        profVal = character.type.getCon();
    }
    if (a.proficiencyAbility == "Dexterity")
    {
        profVal = character.type.getDex();
    }
    if (a.proficiencyAbility == "Wisdom")
    {
        profVal = character.type.getWis();
    }
    if (a.proficiencyAbility == "Charisma")
    {
        profVal = character.type.getCha();
    }

    profVal = floor(profVal/2 -5);
    return profVal;

}

int getAbilityModiferEnemy(Attack a, Creature & enemy)
{
    int profVal;
    if (a.proficiencyAbility == "Strength")
    {
        profVal = enemy.getStrength();
    }
    if (a.proficiencyAbility == "Intelligence")
    {
       profVal = enemy.getInt();
    }
    if (a.proficiencyAbility == "Constitution")
    {
        profVal = enemy.getCon();
    }
    if (a.proficiencyAbility == "Dexterity")
    {
        profVal = enemy.getDex();
    }
    if (a.proficiencyAbility == "Wisdom")
    {
        profVal = enemy.getWis();
    }
    if (a.proficiencyAbility == "Charisma")
    {
        profVal = enemy.getCha();
    }

    profVal = floor(profVal/2 -5);
    return profVal;


}