
#include <iostream>
#include <vector>
#include "simulation.hpp"
#include "critter.hpp"
#include "utility.hpp"
using std::cout;
using std::endl;

//constructor
Simulation::Simulation()
{
}	

//destructor
Simulation::~Simulation()
{
	//deallocate remaining critters
	for (int i = 0; i < maxRows; i++)
	{
		for (int n = 0; n < maxColumns; n++)
		{
			if (board[i][n] != NULL)
			{
				delete board[i][n];
			}
		}
	}

	//delete the array
	delete [] board;	
}

/*****************************************************************************
** Description:	runs the entire simulation. Calls initialization function
		then plays turns until simulation is supposed to end
*****************************************************************************/
void Simulation::run()
{
	//initialize
	initialize();

	//simulate for X turns
	for (int i = 0; i < maxSteps; i++)
	{
		//age animals
	/*
		for (int i = 0; i < maxRows; i++)
		{
			for (int n = 0; n < maxColumns; n++)
			{
				if (board[i][n] != NULL)
				{
					board[i][n]->ageUp();
				}
			}
		}
	*/

		//move doodlebugs
	
		//check doodlebugs for starvation, kill if necessary	
	//starve();
	
		//move ants

		//breed criters
	//breedEveryone();
		
		//display results of the turn
		cout << "Step: " << i << endl;
		displayBoard();
	}
}

/*****************************************************************************
** Description:	function to ask user about various initialization parameters
		before the simulation runs. Creates/populates the array then
		adds the desired number of doodle bugs and ants to it.
** parameters: none
** return: none
*****************************************************************************/
void Simulation::initialize()
{
	//get size of the board
	cout << "Enter the number of columns in the board " << endl;
	maxColumns = getInt(1, 80);
	
	cout << "Enter the number of rows in the board " << endl;
	maxRows = getInt(1,80);

	//get number of doodle bugs to spawn (limit based on size of board)
	cout << "How many dooblebugs should be initially spawned on the board: " << endl;
	int numDoodle = getInt(1, maxColumns * maxRows);
	
	//get number of ants to spawn (limit based on size of board and number
	//of doodlebugs)
	cout << "How many ants should be initially spawned on the board: " << endl;
	int numAnts = getInt(1, maxColumns * maxRows - numDoodle);

	
	//get number of steps (limit based on size of board)
	cout << "Enter the number of steps the game will run for: " << endl;
	maxSteps = getInt(1, 10000000);


	//create the board
	board = new Critter**[maxRows];
	for (int i = 0; i < maxRows; i++)
	{
		board[i] = new Critter*[maxColumns];
	}

	//populate board with null pointers
	for (int i = 0; i < maxRows; i++)
	{
		for (int n = 0; n < maxColumns; n++)
		{
			board[i][n] = NULL;
		}
	}

/*
	//randomly add all desired doodlebugs
	int crittersAdded = 0;
	while(crittersAdded != numDoodle) 
	{
		//generate random position
		int row = getRandNum(0, maxRows-1);
		int col = getRandNum(0, maxColumns-1);
		
		//check if its allowed to add a doodlebug there
		if (board[row][col] == NULL)
		{
			//add a doodblebug at that position
			board[row][col] = new Doodlebug;
			//update critters added
			crittersAdded++;	
		}
	}

	//randomly add all desired ants
	crittersAdded = 0;
	while(crittersAdded != numAnts) 
	{
		//generate random position
		int row = getRandNum(0, maxRows-1);
		int col = getRandNum(0, maxColumns-1);
		
		//check if its allowed to add a doodlebug there
		if (board[row][col] == NULL)
		{
			//add a doodblebug at that position
			board[row][col] = new Ant;
			//update critters added
			crittersAdded++;	
		}
	}
*/
}

		
void Simulation::displayBoard()
{
	//print line to delineate start of grid
	cout << string (2*maxColumns, '-') << endl;
	
	for (int row = 0; row < maxRows; row++)
	{
		for (int col = 0; col < maxColumns; col++)
		{
			//print lines to form grid
			cout << '|';
			//print blank space if it's a null pointer 
			if (board[row][col] == NULL)
			{
				cout << " ";
			}
			//print ant symbol for ants
			else if(true)
			{
				cout << "O";
			}
			//print doodlebug symbol
			else
			{
				cout << "X";
			}
		}
		
		//carriage return at the end of each row
		cout << '|' << endl;
	}
	//print line to delineate end of grid
	cout << string (2*maxColumns, '-') << endl << endl;
}	
