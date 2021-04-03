#include "ui.h"

int renderMainMenu()
{
        int user_choice;
        cout << "Your choices are: " << endl;
        cout <<"\t 1. Create Role" << endl;
        cout <<"\t 2. Create Species" << endl;
        cout <<"\t 3. See lists" << endl;
        cout <<"\t 4. Create a new individual " << endl;
        cout <<"\t 5. See list individuals" << endl;
        cout <<"\t 6. Select Individual for editing / deleting / taking damage test" << endl;
        cout <<"\t 7. Remove Individual Type" << endl;
        cout <<"\t 8. Testing area" << endl;
        cout <<"\t 0. quit" << endl;

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
        cout << "1. Basic" << endl;
        cout << "2. Custom" << endl;
        cin >>basicOrCustom;
        return basicOrCustom;
}

int uiNPCOrPC()
{
        int npc_pc;
        cout <<"Would you like to create: " << endl;
        cout <<"1. NPC" << endl;
        cout <<"2. Investigator" << endl;
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
        printAllTypes();
        cin >> userChoice;
        return userChoice;
}

int uiEditIndividuals()
{
        int userChoice;
        cout << "What type of individual would like to edit? " << endl;
        printAllTypes();
        cin >> userChoice;
        return userChoice;
}

int uiStatToEdit()
{
        int userChoice;                
        cout << "What would you like to edit? " << endl;
        cout << "1. Life" << endl;
        cout << "2. Strength" << endl;
        cout << "3. Nature" << endl;
        cout << "4. Disquiet " << endl;
        cout << "5. Intelligence " << endl;
        cout << "Your selection: ";
        cin >> userChoice;
        return userChoice;
}