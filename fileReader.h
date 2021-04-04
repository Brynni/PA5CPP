#ifndef FILEREADER_12314123
#define FILEREADER_12314123

#include <iostream>
#include <string>
#include "role.h"
#include "creature.h"
#include "encounter.h"

class FileReader
{
    public:
        void ReadRolesFromFile(vector <Role> &roles);
        void ReadCreaturesFromFile(vector <Creature> &creatures);
        void RemoveCreatureFromFile(Creature sp, string fileName);
        void RemovePersonRoleFromFile(Role role, string filename);
        void ReadEncounterFromFile(vector <Encounter> encounters_vector, vector <Creature> creatures_vector);
        Role createRole(vector <Role> roles);
        Creature createSpecies(vector <Creature> species_vector);
        void createEncounter(Encounter encounter);
};


#endif