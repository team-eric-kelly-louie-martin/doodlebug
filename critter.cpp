
#include "critter.hpp"


/*****************************************************************************
** Description:	Critter...
*****************************************************************************/

//constructors & destructors
Critter::Critter()
{
    this->age = 0;
}

Critter::~Critter()
{
}

//getters
int Critter::getAge()
{
    return age;
}

//misc.	
void Critter::incrementAge()
{
    age++;
}


/*****************************************************************************
** Description:	Doodlebug...
*****************************************************************************/

//constructors & destructors
Doodlebug::Doodlebug()
{
    this->lastMeal = 0;
}

Doodlebug::~Doodlebug()
{
}

//getters
int Doodlebug::getLastMeal()
{
    return lastMeal;
}

//misc.
void Doodlebug::incrementLastMeal()
{
    lastMeal++;
}

void Doodlebug::resetLastMeal()
{
    lastMeal = 0;
}

char Doodlebug::symbol()
{
    return 'X';
}

/*****************************************************************************
** Description:	Ant...
*****************************************************************************/

//constructors & destructors
Ant::Ant()
{
}

Ant::~Ant()
{
}

char Ant::symbol()
{
    return 'O';
}
