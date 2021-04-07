#ifndef INVESTIGATOR_12314123
#define INVESTIGATOR_12314123

#include <iostream>
#include <vector>
#include "person.h"
#include "investigator.h"
#include "individuals.h"
#include "ui.h"
#include <string>
#include "role.h"

class Investigator :public Person
{
    public:
        Investigator();
        Investigator(string name, int life, int strength, int intelligence, int constitution, int dexterity, int wisdom, int charisma, string gender, int fear, int terror);
        friend ostream& operator <<(ostream& out, const Investigator i);
        void updateTerror();
        int getTerror();
        int terror;
        void printCharacter();
};

Investigator createInvestigator(Role role);
Investigator createCustomInvestigator();
Person createPerson(Role role);
int getNumberOfRoles(vector<Individuals<Person> > individualsPersons, string name);
void createPersonAndAddToVector(vector <Role> roles, vector<Individuals<Investigator>> &investigators, vector <Individuals<Person> >& individualsPersons);
void printIndividualInvestigator(vector <Individuals<Investigator> > investigators);
Individuals<Investigator> selectIndividualInvestigator(vector <Individuals<Investigator> > investigators);
#endif

