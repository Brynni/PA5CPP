#include "attack.h"
#include "battle.h"
#include "being.h"
#include "dice.h"
#include "encounter.h"
#include "fileReader.h"
#include "individuals.h"
#include "investigator.h"
#include "person.h"
#include "speciesCreature.h"
#include "role.h"
#include "weapon.h"
#include "ui.h"


#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm> 
#include <vector>


using namespace std;

void printIndividualPersons(vector <Individuals<Person> > individualPersons)
{
    int counter = 0;
    cout << "Printing Individuals of type Person" << endl;
    for (Individuals<Person> p: individualPersons)
    {
        counter ++;
        cout << counter << ". " << p.getName() << " " << p.getCounter() << endl;
        
    }
}

void printIndividualCreature(vector <Individuals<Creature> > individualCreature)
{
    int counter = 0;
    cout << "Printing Individuals of type Creature" << endl;
    for (Individuals<Creature> c: individualCreature)
    {
        counter ++;
        cout << counter << ". " << c.getName()  << " " << c.getCounter() << endl;
    }
}

int selectIndividualEncounter(vector <Encounter> encounters)
{
    seeAllEncounters(encounters);
    cout << endl;
    int selection;
    cout << "Select what encounter you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > encounters.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << encounters.size() << endl;
        cout << "Select what encounter you would like to select for editing: ";
        cin >> selection;
    }

    return selection-1;
}

Individuals<Creature> selectIndividualCreature(vector <Individuals<Creature> > individualCreatures)
{
    printIndividualCreature(individualCreatures);
    cout << endl;
    int selection;
    cout << "Select what creature you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualCreatures.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualCreatures.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualCreatures[selection -1];
}

Individuals<Person> selectIndividualPerson(vector <Individuals<Person> > individualPersons)
{
    printIndividualPersons(individualPersons);
    cout << endl;
    int selection;
    cout << "Select what person you would like to select for editing: ";
    cin >> selection;
    while(selection < 1 || selection > individualPersons.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << individualPersons.size() << endl;
        cout << "Select what creature you would like to select for editing: ";
        cin >> selection;
    }

    return individualPersons[selection -1];
}

int getIndexOfInvestigator(vector <Individuals<Investigator> > investigators)
{
    printIndividualInvestigator(investigators);
    cout << endl;
    int selection;
    cout << "Select an PC: ";
    cin >> selection;
    while(selection < 1 || selection > investigators.size())
    {
        cout << "Invalid Selection!, your range is 1 - " << investigators.size() << endl;
        cout << "Select an PC: ";
        cin >> selection;
    }

    return (selection -1);
}


/* _________________________________*/
//       Main starts here!         //
/* ______________________________ */

int main()
{
    //All vectors pertaining to beings
    vector <Role> roles;
    vector <Creature> creatures;
    vector <Attack> attacks;
    vector <Weapon> weapons;
    vector <Individuals<Investigator>> investigators;
    vector <Individuals<Person> > individualsPersons;
    vector <Individuals<Creature> > IndividualsCreatures;
    vector <Individuals<Investigator>> gameInvestigators;

    //All vectors pertaining to game mechanics
    vector <Dice> allDice;
    initializeBaseDice(allDice);
    vector <Encounter> allEncounters;

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

    // Create an attack vector for unarmed attacks
    vector <Attack> unarmedHumanAttacks;
    Attack punch = Attack();
    unarmedHumanAttacks.push_back(punch);
    attacks.push_back(punch);

    vector <Attack> unarmedBeastAttacks;
    Attack bite = Attack("Bite", "Strength", selectIndividualDiceByNickname(allDice,"D6"), 1);
    Attack scratch = Attack("Scratch", "Strength", selectIndividualDiceByNickname(allDice,"D4"), 1);
    unarmedBeastAttacks.push_back(bite);
    unarmedBeastAttacks.push_back(scratch);
    attacks.push_back(bite);
    attacks.push_back(scratch);
    for (int i = 0; i < attacks.size(); i++)
    {
        cout << attacks[i];
    }
    // Create an attack vector for weapon attacks
    
        //Melee weapons use strength
    vector <Attack> swordAttacks;
    Attack slash = Attack("Slash", "Strength", selectIndividualDiceByNickname(allDice,"D8"), 1);
    Attack franticSlashes = Attack("Frantic slashes", "Strength", selectIndividualDiceByNickname(allDice,"D4"), 3);
    Attack stab = Attack("Stab", "Strength", selectIndividualDiceByNickname(allDice,"D8"), 1);
    
    swordAttacks.push_back(slash);
    swordAttacks.push_back(franticSlashes);
    swordAttacks.push_back(stab);

    vector <Attack> warhammerAttacks;
    Attack crush = Attack("Crush", "Strength", selectIndividualDiceByNickname(allDice,"D12"), 1);
    warhammerAttacks.push_back(crush);

        //Ranged weapons use Dexterity
    vector <Attack> bowAttack;
    Attack letBow = Attack("Fire bow", "Dexterity", selectIndividualDiceByNickname(allDice,"D8"), 1);
    bowAttack.push_back(letBow);
    

    // Create an attack vector for spells?


    //Create the weapons to be used
    Weapon sword("Sword");

    sword.AddAttacksToWeapon(swordAttacks);
    Weapon warhammer("Warhammer");
    warhammer.AddAttacksToWeapon(warhammerAttacks);
    Weapon bow("Bow");
    bow.AddAttacksToWeapon(bowAttack);
    weapons.push_back(sword);
    weapons.push_back(bow);
    weapons.push_back(warhammer);
    
    
    //Initialize all the needed data for the game to function
    FileReader myFileReader; 
    myFileReader.ReadRolesFromFile(roles);
    myFileReader.ReadCreaturesFromFile(creatures, attacks, weapons);
    myFileReader.ReadEncounterFromFile(allEncounters, creatures);
    

    //Test adding weapons to a character and adding unarmed attacks as well
    /* Investigator man("Warrior man", 9, 15, 12, 13, 14, 10, 8, "Male", 5, 1);
    man.AddWeaponToBeing(sword);
    man.AddWeaponToBeing(bow);
    man.AddAttackToBeing(punch);
    man.printAttacks();
    int manInit = man.getInitiative();
    cout << "This is the initive: " << manInit << endl; */

    Investigator man("Warrior man", 9, 15, 12, 13, 14, 10, 8, "Male", 5, 1);
    man.AddWeaponToBeing(sword);
    man.AddWeaponToBeing(bow);
    man.AddAttackToBeing(punch);
    man.printAttacks();
    int manInit = man.getInitiative();
    cout << "This is the initiative: " << manInit << endl;
    Investigator newI = Investigator (man.getName(), man.getLife(), man.getStrength(), man.getInt(), man.getDex(), man.getCon(), man.getWis(), man.getCha(),  man.getGender(), man.getFear(), man.getTerror());
    
    newI.updateCurrentLife(man.getCurrentLife());
    newI.printCharacter();
    newI.AddWeaponToBeing(sword);
    newI.AddWeaponToBeing(bow);
    newI.AddAttackToBeing(punch);
    Individuals<Investigator> t = Individuals<Investigator>("", newI, 1, "");

    investigators.push_back(t);


    bool playing = true;

    while (playing)
    {
        int user_choice = renderMainMenu();

        if (user_choice == 1){
                //Path 1 Create Human
                createPersonAndAddToVector(roles, investigators, individualsPersons);
            }

        else if (user_choice == 2){
            //Path 2 completed
            //Create Encounter Path
            Encounter newEncounter;
            bool hasBeenSaved = false;
            while (!hasBeenSaved)
            {
                int userChoice1 = uiCreateEncounter(newEncounter.creatures.size());
                // if he wants to select from the already existing plethora of characters
                if (userChoice1 == 1)
                {
                    string typeOfCreature = uiSelectBeingType();
                    cout << typeOfCreature << endl;

                    //Find how many creatures of the type exist
                    int tempCreaturesCount = countAllCreaturesOfType(creatures, typeOfCreature);
                    if (tempCreaturesCount > 0)
                    {
                        Creature selectedCreature = selectCreatureWithType(creatures, typeOfCreature);
                        newEncounter.addEnemyToEncounter(selectedCreature);
                    } else{
                        cout << "Error! No creature of type " << typeOfCreature << endl;
                        system("pause");
                    }
                }
                //If the user wants to create his own custom enemy type
                else if (userChoice1 == 2)
                {
                    creatures.push_back(myFileReader.createSpecies(creatures));
                } 
                // Attempt to save
                else if (userChoice1 == 3) {
                    if (newEncounter.creatures.size() == 0)
                    {
                        cout << "Error! Nothing added to the encounter! Exiting...." << endl;
                        hasBeenSaved = true;
                        system("pause");
                    } else {
                        string difficultyLevel = uiSelectDifficulty();
                        newEncounter.changeDifficulty(difficultyLevel);
                        allEncounters.push_back(newEncounter);
                        myFileReader.createEncounter(newEncounter);
                        cout << "Success! Encounter has been saved ...." << endl;
                        system("pause");
                        cout << newEncounter << endl;
                        hasBeenSaved = true;
                    }
                } else {
                    cout << "Invalid Choice! Try again!" << endl;
                }
            }   
        }

        else if (user_choice == 3)
        {
            //Path 3 create weapons/attacks
            int w_or_s; 
            cout << "Would you like to create: " << endl;
            cout << "1. Weapon" << endl;
            cout << "2. Attack" << endl;
            cin >> w_or_s;
            while(w_or_s < 1 || w_or_s > 2){
                cout << "invalid input" << endl;
                cout << "Would you like to create: " << endl;
                cout << "1. Weapon" << endl;
                cout << "2. Attack" << endl;
                cin >> w_or_s;
            }
            if (w_or_s == 1 ){
                Weapon newWep = createIndividualWeapon();
                char addAttack;
                cout << "Would you like to create an Attack and assign it to the weapon? (y/n)" << endl;
                cin >> addAttack;
                if (addAttack == 'y')
                {
                    vector<Attack> newVect;
                    bool addingToWeapon = true;
                    while (addingToWeapon)
                    {
                        Attack newAttack = createIndividualAttack(allDice);
                        newVect.push_back(newAttack);
                        char keepAdding;
                        cout << "Would you like to another attack to the weapon? (y/n)" << endl;
                        cin >> keepAdding;
                        if(keepAdding != 'y'){
                            addingToWeapon = false;
                        } 
                    }
                    newWep.AddAttacksToWeapon(newVect);
                    cout << "This is your new weapon"<< endl;
                    cout << newWep << endl;
                    
                }

            }
            else
            {
                Attack newAttack = createIndividualAttack(allDice);
                cout << "This is your new attack" << endl;
                cout << newAttack << endl;
                attacks.push_back(newAttack);
            }
        }

        else if (user_choice == 4){
            //Path 4 Add attack to weapon/being
            int userChoice = uiAttackAdder();
            if (userChoice == 1)
            {
                string enemyType = uiSelectBeingType();
                int selectedCreature = selectCreatureWithIndex(creatures);
                Attack selectedAttack = selectAttack(attacks);
                cout << "BEFORE UPDATE ATTACKS" << endl;
                creatures[selectedCreature].printAttacks();
                creatures[selectedCreature].AddAttackToBeing(selectedAttack);
                //selectedCreature.printAttacks();
                cout << "AFTER UPDATE" << endl;
                creatures[selectedCreature].printAttacks();

            }
            if (userChoice == 2)
            {
                int userChoice = uiSelectNPCOrPC();
                if (userChoice == 1)
                {
                    
                    Individuals<Person>  p = selectIndividualPerson(individualsPersons);
                    Attack selectedAttack = selectAttack(attacks);
                    p.getType().printAttacks();
                    p.type.AddAttackToBeing(selectedAttack);
                    p.type.printAttacks();
                }
                if (userChoice == 2)
                {
                    
                    Individuals<Investigator>& inv = selectIndividualInvestigator(investigators);
                    Attack selectedAttack = selectAttack(attacks);
                    inv.type.AddAttackToBeing(selectedAttack);
                    inv.getType().printAttacks();
                    inv.type.printAttacks();


                }
            }
            if (userChoice == 3)
            {
                //Todo perhaps add the choice to pick a premade attack for a weapon
                // You would have to create a new vector called weapon attacks and allow the old one to be renamed unarmed attacks
                Weapon selectedWeapon = selectWeapon(weapons);
                Attack newAttack = createIndividualAttack(allDice);
                cout << "This is your new attack" << endl;
                cout << newAttack << endl;
                selectedWeapon.AddAttackToWeapon(newAttack);
            }
        }

        else if (user_choice == 5){
            //Path 5 Add weapon to being
            int userChoice = uiWeaponAdder();
            if (userChoice == 1)
            {
                string enemyType = uiSelectBeingType();
                int selectedCreature = selectCreatureWithIndex(creatures);
                Weapon selectedWeapon = selectWeapon(weapons);
                cout << "BEFORE UPDATE ATTACKS" << endl;
                creatures[selectedCreature].printAttacks();
                creatures[selectedCreature].AddWeaponToBeing(selectedWeapon);
                //selectedCreature.printAttacks();
                cout << "AFTER UPDATE" << endl;
                creatures[selectedCreature].printAttacks();

            }
            if (userChoice == 2)
            {
                int userChoice = uiSelectNPCOrPC();
                if (userChoice == 1)
                {
                    
                    Individuals<Person>  p = selectIndividualPerson(individualsPersons);
                    Weapon selectedWeapon = selectWeapon(weapons);
                    p.getType().printAttacks();
                    p.type.AddWeaponToBeing(selectedWeapon);
                    p.type.printAttacks();
                }
                if (userChoice == 2)
                {
                    Individuals<Investigator>& inv = selectIndividualInvestigator(investigators);
                    Weapon selectedWeapon = selectWeapon(weapons);
                    inv.type.AddWeaponToBeing(selectedWeapon);
                    inv.getType().printAttacks();
                    inv.type.printAttacks();
                }
            }
        }
        
        else if (user_choice == 6)
        {
            //Path 6 Select Being to edit
            int userchoice1 = uiPrintAllTypes ();
            if (userchoice1 == 1)
            {
                int userchoice2 = uiNPCOrPC();
                if (userchoice2 == 1)
                {
                    cout << "selected NPC" << endl;
                    if (individualsPersons.size() != 0)
                    {
                        Individuals<Person> p = selectIndividualPerson(individualsPersons);
                        cout << "Selected person: " << endl;
                        p.printA();
                        string editing = uiUpdateStat();
                        if (editing != "cancel")
                        {
                            p.type.updateStat(editing);
                            Person newP = Person (p.type.getName(), p.type.getLife(), p.type.getStrength(), p.type.getInt(), p.type.getDex(), p.type.getCon(), p.type.getWis(), p.type.getCha(), p.type.getGender(), p.type.getFear());
                            string name = p.getName();
                            string job = p.getJob();
                            int count = p.getCounter();
                            Individuals<Person> t = Individuals<Person>(name, newP, count, job);
                            for (int i=0; i<individualsPersons.size();i++)
                            {
                                if (individualsPersons[i].getName() == p.getName() && individualsPersons[i].getCounter() == p.getCounter() )
                                {
                                individualsPersons.erase(individualsPersons.begin() + i);
                                individualsPersons.push_back(t);
                                }
                            }
                            cout << "updated Person" << endl;
                            t.printA();
                            
                            cout << endl;
                            sort(individualsPersons.begin(), individualsPersons.end());
                        }
                    } else {
                        cout << "Error! No NPC's found in system!" << endl;
                        system("pause");
                    } 
                                    
                }
                if (userchoice2 == 2)
                {
                    cout << "selected PC" << endl;
                    if (investigators.size() != 0)
                    {
                        Individuals<Investigator> inv = selectIndividualInvestigator(investigators);
                        cout << "Selected investigator: " << endl;
                        inv.printA();
                        string editing = uiUpdateStat();
                        if (editing != "cancel")
                        {
                            inv.type.updateStat(editing);
                            Investigator newI = Investigator (inv.type.getName(), inv.type.getLife(), inv.type.getStrength(), inv.type.getInt(), inv.type.getDex(), inv.type.getCon(), inv.type.getWis(), inv.type.getCha(),  inv.type.getGender(), inv.type.getFear(), inv.type.getTerror());
                            string name = inv.getName();
                            string job = inv.getJob();
                            int count = inv.getCounter();
                            newI.updateCurrentLife(inv.type.getCurrentLife());
                            newI.printCharacter();
                            Individuals<Investigator> t = Individuals<Investigator>(name, newI, count, job);
                            for (int i=0; i<investigators.size();i++)
                            {
                                if (investigators[i].getName() == inv.getName() && investigators[i].getCounter() == inv.getCounter() )
                                {
                                    investigators.erase(investigators.begin() + i);
                                    investigators.push_back(t);
                                    
                                }
                            }
                            cout << " Updated Investigator" << endl;
                            t.printA();
                            cout << endl;
                            sort(investigators.begin(), investigators.end());
                        }
                    } else {
                        cout << "Error! No PC's found in system!" << endl;
                        system("pause");
                    }
                }
            }
            if (userchoice1 == 2)
            {
                if (creatures.size() != 0){
                    // start by listing all creatures
                    //TODO CREATURE STUFFFFFFFFFF
                    string type = uiSelectBeingType();
                    Creature cre = selectCreatureWithType(creatures, type);
                    // select stat to edit
                    int index = 0;
                    for (Creature cr : creatures)
                    {
                        if (cr.getName() == cre.getName())
                        {
                            break;
                        }
                        index ++;
                    }
                    cout<< index << endl;
            
                    string statToEdit = uiUpdateStat();
                    if (statToEdit != "cancel")
                    {
                        cre.updateStat(statToEdit);
                        Creature newCre = createCreature(cre);
                            for (int i=0; i<creatures.size();i++)
                            {
                                if (creatures[i].getName() == cre.getName())
                                {
                                    creatures.erase(creatures.begin() + i);
                                    creatures.push_back(newCre); 
                                }
                            }
                    }
                    
                } else {
                    cout << "Error! No enemies found in system!" << endl;
                    system("pause");
                }
            }
        }

        else if (user_choice == 7)
        {
            //Path 7 edit/remove encounter
            //TODO write to file the change
            if (allEncounters.size() > 0)
            {
                cout << "Edit/remove encounters" << endl;
                int selectedEncounter = selectIndividualEncounter(allEncounters);
                int userChoice = uiEditEncounter();
                if (userChoice == 1)
                {
                    cout << "What creature do you wish you remove?" << endl;
                    seeAllCreatures(allEncounters[selectedEncounter].creatures);
                    int userChoice2;
                    cin >> userChoice2;
                    if (userChoice2 > 0 &&  userChoice2 <= allEncounters[selectedEncounter].creatures.size()+1){
                        allEncounters[selectedEncounter].creatures.erase (allEncounters[selectedEncounter].creatures.begin()+userChoice2-1);
                        if (allEncounters[selectedEncounter].creatures.size() == 0){
                            allEncounters.erase (allEncounters.begin()+selectedEncounter);      
                        }
                    } else {
                        cout << "Error selection out of range!" << endl;
                        system("pause");
                    }
                }
                else if (userChoice == 2)
                {
                    string typeOfCreature = uiSelectBeingType();
                    cout << typeOfCreature << endl;

                    //Find how many creatures of the type exist
                    int tempCreaturesCount = countAllCreaturesOfType(creatures, typeOfCreature);
                    if (tempCreaturesCount > 0)
                    {
                        Creature selectedCreature = selectCreatureWithType(creatures, typeOfCreature);
                        allEncounters[selectedEncounter].addEnemyToEncounter(selectedCreature);
                    } else{
                        cout << "Error! No creature of type " << typeOfCreature << endl;
                        system("pause");
                    }
                }
                else if (userChoice == 3)
                {
                    string newDifficulty = uiSelectDifficulty();
                    allEncounters[selectedEncounter].changeDifficulty(newDifficulty);

                    
                    cout << "Current difficulty: " << allEncounters[selectedEncounter].difficulty << endl;
                    
                }
                else if (userChoice == 4)
                {
                    allEncounters.erase (allEncounters.begin()+selectedEncounter);        
                }
                
            } else {
                cout << "Error! No encounters found!" << endl;
                system("pause");
            }
        }

        else if(user_choice == 8)
        {
            //Path 8 Select or remove playable character to/from game session
            int userChoice = uiSelectOrRemoveFromEncounter();
            if (userChoice == 1)
            {
                //Add character to game
                if (investigators.size() != 0)
                {
                    gameInvestigators.push_back(selectIndividualInvestigator(investigators));
                } else {
                    cout << "Error! No investigators in the system!" << endl;
                    system("pause");
                } 
            }
            if (userChoice == 2)
            {
                //Remove character from game
                if (gameInvestigators.size() != 0)
                {
                    for (int i = 0; i < gameInvestigators.size(); i++)
                    {

                        int userChoice2 = getIndexOfInvestigator(gameInvestigators);
                        gameInvestigators.erase (gameInvestigators.begin()+userChoice2);
                    }
                } else{
                    cout << "Error! No investigators in the system!" << endl;
                    system("pause");
                }
                
            }
        }

        else if(user_choice == 9)
        {
            //Path 9 Start encounter!
            if (gameInvestigators.size() > 0)
            {// Start by seleting encounter
            int randEnc;

            cout << "Would you like to get a " << endl;
            cout << "1. Easy encounter" << endl;
            cout << "2. Medium encounter" << endl;
            cout << "3. Hard encounter" << endl;
            cout << "4. Impossible encounter" << endl;
            cin >> randEnc;
            while(randEnc < 1 || randEnc > 4){
                cout << "INVALID SELECTION!!!!" << endl;
                cout << "Would you like to get a " << endl;
                cout << "1. Easy encounter" << endl;
                cout << "2. Medium encounter" << endl;
                cout << "3. Hard encounter" << endl;
                cout << "4. Impossible encounter" << endl;
                cin >> randEnc;
            }

            Encounter selEnc = getRandomEncounter(randEnc-1, allEncounters);
            vector<Individuals<Investigator>> selInv;
            bool keepAdding = true;
            int addingNum;
            while (keepAdding)
            {
                cout << "Add Characters" << endl;
                
                selInv.push_back(selectIndividualInvestigator(gameInvestigators));
                
                // This is the shit we need to fix
                selInv[0].type.printAttacks();
                cout << "Keep adding?" << endl;
                cout <<"1. yes" << endl;
                cout <<"2. no" << endl;
                cin >> addingNum;
                while (addingNum > 2 || addingNum < 1)
                {
                    cout << "invalid selection" << endl;
                    cout << "Keep adding?" << endl;
                    cout <<"1. yes" << endl;
                    cout <<"2. no" << endl;
                    cin >> addingNum;
                }

                if (addingNum == 2)
                {
                    keepAdding = false;
                }
            }
            battleEnv(selEnc, selInv);
            } else {
                cout << "Error! No investigator found!" << endl;
                system("pause");
            }
        }

        else if (user_choice == 0)
        {
            playing = false;
        }

        else
        {
            cout << "Invalid choice!" << endl;
        }

    }

    return 0;
}