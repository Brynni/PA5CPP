#include "ui.h"

// Helper functions

int getNumberOfCreatures(vector<Individuals<Creature>>individualsCreatures, string name)
{
    int counter = 0;

     for (Individuals<Creature> cre : individualsCreatures)
     {
        if(cre.getJob() == name)
        {
            counter ++;
        }
    }

    return counter;
}


int renderMainMenu()
{
        int user_choice;
        cout << "\t\tMain menu" << endl;
        cout << "__________________________________" << endl;
        cout << "Your choices are: " << endl;
        cout << "__________________________________" << endl;
        cout <<"\t 1. Create Role" << endl;
        cout <<"\t 2. Create Species" << endl;
        cout <<"\t 3. See lists" << endl;
        cout <<"\t 4. Create a new individual " << endl;
        cout <<"\t 5. See list individuals" << endl;
        cout <<"\t 6. Select Individual for editing / deleting / taking damage test" << endl;
        cout <<"\t 7. Remove Individual Type" << endl;
        cout <<"\t 8. Testing area" << endl;
        cout <<"\t 0. quit" << endl;
        cout << "__________________________________" << endl;

        cout << "Enter choice here: ";
        cin >> user_choice;
        cout << " " << endl;
        return user_choice;
};

int uiCreatureOrHorror()
{
        int creature_or_horror;
        cout << "Would you like your species to be: \n\t1.Creature\n\t2.Eldritch Horror: ";
        cin >> creature_or_horror;
        return creature_or_horror; 
}

int uiRenderListOfType()
{
        int whatList;
        cout << "Would you like to see list of: " << endl;
        cout << "__________________________________" << endl;
        cout << "1. Species" << endl;
        cout << "2. Horrors" << endl;
        cout << "3. Roles" << endl;
        cout << "Your selection here: ";
        cin >> whatList;
        return whatList;
};

int uiDetailListOrCompactList()
{
        int detailOrCompact;
        cout << "Would you like see: " << endl;
        cout << "__________________________________" << endl;
        cout << "1. Compact view" << endl;
        cout << "2. Detailed view" << endl;
        cout << "Your choice here: ";
        cin >> detailOrCompact;
        cout << endl;
        return detailOrCompact;
};

int uiSelectCHP()
{
        int select_creature_horror_person;
        cout << "Would you like to select\n\t1.Creature\n\t2.Horror\n\t3.Person"<< endl;
        cin >>select_creature_horror_person;
        return select_creature_horror_person;
}

int uiBasicOrCustom()
{
        int basicOrCustom;
        cout << "Would you like to create a basic or a custom Individual? " << endl;
        cout << "__________________________________" << endl;
        cout << "1. Basic" << endl;
        cout << "2. Custom" << endl;
        cin >>basicOrCustom;
        return basicOrCustom;
}

int uiNPCOrPC()
{
        int npc_pc;
        cout <<"Would you like to create: " << endl;
        cout << "__________________________________" << endl;
        cout <<"1. NPC" << endl;
        cout <<"2. PC" << endl;
        cin >> npc_pc;
        return npc_pc;
}  

void printAllTypes()
{
        cout << "1. Person " << endl;
        cout << "2. Creature " << endl;
        cout << "3. Eldritch Horrors " << endl;
        cout << "4. Investigators " << endl;    
}

int uiIndividualList()
{
        int userChoice;
        cout << "Would you like to see a list of individuals of type: " << endl;
        cout << "__________________________________" << endl;
        printAllTypes();
        cin >> userChoice;
        return userChoice;
}

int uiEditIndividuals()
{
        int userChoice;
        cout << "What type of individual would like to edit? " << endl;
        cout << "__________________________________" << endl;
        printAllTypes();
        cin >> userChoice;
        return userChoice;
}

int uiStatToEdit()
{
        int userChoice;                
        cout << "What would you like to edit? " << endl;
        cout << "__________________________________" << endl;
        cout << "1. Life" << endl;
        cout << "2. Strength" << endl;
        cout << "3. Nature" << endl;
        cout << "4. Disquiet " << endl;
        cout << "5. Intelligence " << endl;
        cout << "Your selection: ";
        cin >> userChoice;
        return userChoice;
}

int uiAttackAdder ()
{
        int userChoice;
        cout << "Which do you want to add attack to?" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Enemy" << endl;
        cout << "2. PC/NPC" << endl;
        cout << "3. Weapon" << endl;
        cin >> userChoice;
        return userChoice;
}

int uiCreateAttack()
{
        int userChoice;
        cout << "Create Attack" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Unarmed attack" << endl;
        cout << "2. Weapon attack" << endl;
        cout << "3. Spell attack" << endl;
        cin >> userChoice;
        return userChoice;
}

int uiCreateHuman()
{
        int userChoice;
        cout << "Create Human" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Player character" << endl;
        cout << "2. Non Player character" << endl;
        cin >>userChoice;
        return userChoice;
}

int uiCreateEncounter()
{
        int userChoice;
        cout << "Create Encounter" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Select enemy from the roster" << endl;
        cout << "2. Create new enemy to add to roster" << endl;
        cout << "3. Save current encounter" << endl;
        cin >> userChoice;
        return userChoice;
};

string uiSelectBeingType()
{
        int typeSelect;
        string type;
        cout << "Select type of enemy" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Humanoid" << endl;
        cout << "2. Animal" << endl;
        cout << "3. Undead" << endl;
        cout << "4. Monstrosity" << endl;
        cin >> typeSelect;
    
    
        while (typeSelect < 1 || typeSelect > 4)
        {
                cout << "Invalid selection - the range is 0 - 3" << endl;
                cout << "Select type of creature: " <<  endl;
                cin >> typeSelect;
                cout << endl;
        } 

    switch(typeSelect) {
      case 1:
         type = "Humanoid"; 
         break;
      case 2:
         type = "Animal";
         break;
      case 3:
         type = "Undead";
         break;
      case 4:
         type = "Monstrosity";
         break;
    }
    return type;
}

string uiSelectDifficulty()
{
        int typeSelect;
        string type;
        cout << "Select difficulty" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Impossible" << endl;
        cin >> typeSelect;
    
    
        while (typeSelect < 1 || typeSelect > 4)
        {
                cout << "Invalid selection - the range is 1 - 4" << endl;
                cout << "Select difficulty: " <<  endl;
                cin >> typeSelect;
                cout << endl;
        } 

    switch(typeSelect) {
      case 1:
         type = "Easy"; 
         break;
      case 2:
         type = "Medium";
         break;
      case 3:
         type = "Hard";
         break;
      case 4:
         type = "Impossible";
         break;
    }
    return type;
}

int uiEditEncounter()
{
        int userChoice;
        cout << "Edit Encounter" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Remove creature/s from the chosen encounter" << endl;
        cout << "2. Add creature/s to the chosen encounter" << endl;
        cout << "3. Change difficulty" << endl;
        cout << "4. Delete Encounter" << endl;
        cin >> userChoice;
        return userChoice;  
};

int uiSelectOrRemoveFromEncounter()
{
        int userChoice;
        cout << "Select/Remove character from game session" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Add character to game session" << endl;
        cout << "2. Remove character to game session" << endl;
        cin >> userChoice;
        return userChoice;    
};

int uiAddOrSaveRoster()
{
        int userChoice;
        cout << "Add more to roster or save current roster" << endl;
        cout << "__________________________________" << endl;
        cout << "1. Add more enemies to encounter" << endl;
        cout << "2. Save current encounter" << endl;
        cin >> userChoice;
        return userChoice;
};


void uiCreateIndividualCreature(vector <Creature> creatures, vector<Individuals<Creature>>IndividualsCreatures, string typeOfCreature){
    
    
    if(creatures.size() > 0)
    {
        Creature cre = selectCreatureWithType(creatures, typeOfCreature);

        int basicOrCustom = uiBasicOrCustom();

        if (basicOrCustom == 1)
        {
        Creature beast = createCreature(cre);
        int countOfCreatures = getNumberOfCreatures(IndividualsCreatures, cre.getName());
        string name = cre.getName();
        Individuals<Creature> t = Individuals<Creature>(name, beast, countOfCreatures +1, cre.getName());
        IndividualsCreatures.push_back(t);
        t.printA();
        cout << endl;

        }

        if (basicOrCustom == 2)
        {
        string name; 
        cout << "Enter name for individual: ";
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, name);
        cout << endl;
        Creature beast = createCustomCreature();
        int countOfCreatures = getNumberOfCreatures(IndividualsCreatures, cre.getName());
        Individuals<Creature> t = Individuals<Creature>(name, beast, countOfCreatures +1, cre.getName());
        IndividualsCreatures.push_back(t);
        t.printA();
        cout << endl;
        }

        else if (basicOrCustom != 1 || basicOrCustom !=2) 
        {
            cout << "Invalid choice..." << endl;
        } 
                            
    }

    else
    {
        cout << "There are no creatures..." << endl;
    }
}