
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
/*
void Simulation::moveDoodle() {
	bool valid = false;

    for (int row = 0; row < maxRows; i++) {
        for (int column = 0; column < maxColumns; k++) {
            if (typeid(board[row][column] == typeid(Doodlebug))) {
                
                //increment age of doodlebug
                board[row][column]->incrementAge();

                if (typeid(board[row + 1][column] == typeid(Ant))) {
                   //remove Ant in row and column
                   removeCritter(row + 1, column)
                   
                   //feed Doodlebug use reset last meal
 //edit before     board[row][c)olumn]->resetMeal();
                   
                   //copy critter pointer to new position
                   board[row + 1][column] = board[row][column];
                   
                   //remove criter from previous position
                   removeCritter(row,column);
                              
                }
                else if (typeid(board[row - 1][column] == typeid(Ant))) {
                   removeCritter(row - 1, column)
      
 //edit before     board[row][column]->resetMeal();
                   
                   board[row - 1][column] = board[row][column];
                   
                   removeCritter(row,column);
                }
                else if (typeid(board[row][column + 1] == typeid(Ant))) {
                   removeCritter(row, column + 1)
  
  //edit before    board[row][column]->resetMeal();
  
                   board[row][column + 1] = board[row][column];
                    
                   removeCritter(row,column);
                }
                else if (typeid(board[row][column - 1] == typeid(Ant))) {
                   removeCritter(row, column - 1) 
   
   //edit before   board[row][column]->resetMeal();
   
                   board[row][column - 1] = board[row][column];
                   
                   removeCritter(row,column);
                }
                else {
                    int randNumb = rand(time(NULL) % 4) + 1;

                    if (randNumb == 1 && typeid(board[row + 1][column] == NULL) {
                        //checks if next move is valid
						if (validMove(row + 1, column) {
							//copy critter pointer to new position
                    	    board[row + 1][column] = board[row][column];
                   
                        	//remove criter from previous position
                        	removeCritter(row,column);

                        	//increment last meal
                        	board[row + 1][column]->incrementMeal();
                        
                        	if (board[row + 1][column]->incrementMeal() >= 3) {
                            	removeCritter(row + 1, column);
                        	}
						}
                    }
                    else if (randNumb == 2 &&
                    typeid(board[row - 1][column] == NULL) {
                        
						if (validMove(row - 1, column) {
                        	//copy critter pointer to new position
                        	board[row - 1][column] = board[row][column];
                   
                        	//remove criter from previous position
                        	removeCritter(row,column);
                        
                        	board[row - 1][column]->incrementMeal();
                        
                        	if (board[row - 1][column]->
							incrementLastMeal() >= 3) {
								removeCritter(row - 1, column);
                        	}
                    	}
				 	}
                    else if (randNumb == 3 &&
                    typeid(board[row][column + 1] == NULL) {
                        
						if (validMove(row, column + 1) {
							//copy critter pointer to new position
                        	board[row][column + 1] = board[row][column];
                   
                 	       	//remove criter from previous position
                   		   	removeCritter(row,column);
                        
                        	board[row][column + 1]->incrementLastMeal();
                        
                        	if (board[row][column + 1]->
							incrementLastMeal() >= 3) {
                            	removeCritter(row, column + 1);
                        	}
						}
                    }
                    else if (randNumb == 4 &&
                    typeid(board[row][column - 1] == NULL) {
                        
						if (validMove(row, column - 1) {
   		                    
							//copy critter pointer to new position
        	                board[row][column - 1] = board[row][column];
                   
            	            //remove criter from previous position
                	        removeCritter(row,column);
	
    	                    if (board[row][column - 1]->
							incrementLastMeal() >= 3) {
        	                    removeCritter(row, column - 1);
                        	}
						}
                    }
                }
            }
        }
    }
}

void Simulation::moveAnt() {

    for (int row = 0; row < maxRows; i++) {
        for (int column = 0; column < maxColumns; k++) {
            if (typeid(board[row][column] == typeid(Ant))) {
    
            }
        
        }

    }

}

bool Simulation::validMove(int row, int col) {
    
   if(row < 0) {  
    	return false;
	}
    else if(row = maxRows) {
        return false;
    }     

    else if(col < 0) {  
        return false;
    }
    
    else if(col = maxColmns) {
        return false;
    }
	else {
		return true;
	}
} 
*/

void Simulation::addCritter(int row, int col)
{
    board[row][col] = new Critter;
}

void Simulation::removeCritter(int row, int col)
{
    delete board[row][col];
    board[row][col] = NULL;
}





/*****************************************************************************
** Description:	Breed function checks the age of existing objects on board.
* If old enough to breed, breeding is attempted. 
** parameters: none
** return: none
*****************************************************************************/
void Simulation::breedEveryone()
{
	//iterate through board
	for (int row = 0; row < maxRows; row++) {
		for (int column = 0; column < maxColumns; column++) {
			//if location == ant and ant age % 3
			//attempt to add ant with addCritter()
					//NEED to update add critter to bool to check for success?
			//if location == doodle and doodle age % 8
			//attempt to add doodle
					//again, need bool response for success		
		}
	}
	
}


/*****************************************************************************
** Description:	starve function checks the last time fed on doodlebugs on the 
* board. If == 3, doodlebug killed and removed from board
** parameters: none
** return: none
*****************************************************************************/
void Simulation::starve() {
	//iterate through board
	for (int row = 0; row < maxRows; row++) {
		for (int column = 0; column < maxColumns; column++) {
			if (typeid(board[row][column] == typeid(Doodlebug))) {
				//check for last meal and delete
				if (board[row][column]->getLastMeal() == 3) {
					//kill doodlebug
					removeCritter(row, column);
				}
			}
		}
		
	}
	
}