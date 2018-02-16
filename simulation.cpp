
#include <iostream>
#include <vector>
#include <cstdlib>
#include <typeinfo>
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
		//move doodlebugs
		move();

		//breed criters
		breedEveryone();
		
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
			//else if(typeid(board[row][col]) == typeid(Ant))
			else if (dynamic_cast<Ant*>(board[row][col]))
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

void Simulation::move() {
    
    for (int row = 0; row < maxRows; row++) {
        for (int column = 0; column < maxColumns; column++) {
            if (dynamic_cast <Doodlebug*> (board[row][column])) {
                bool food = true;
                //increment age of doodlebug
                board[row][column]->incrementAge();
                //the following checks whether there is an ant in an adjacent 
                //sqaure
                if (row < maxRows-1 && dynamic_cast <Ant*> (board[row + 1][column])) {
                //if an ant exists the doodlebug moves
                    makeMoveD(row, column, 1, 0, food);
                }
                else if (row > 0 && dynamic_cast <Ant*> (board[row - 1][column])) {
                    makeMoveD(row, column, -1, 0, food);
                }
                else if (column < maxColumns-1 && dynamic_cast <Ant*> (board[row][column + 1])) {
                    makeMoveD(row, column, 0, 1, food);
                }
                else if (column > 0 && dynamic_cast <Ant*> (board[row][column - 1])) {
                    makeMoveD(row, column, 0, -1, food);
                }
                else {
                //if an ant does not exist in an adjacent square the doodle bug
                // will make  random move
                    food = false;
                    int randNumb = (rand() % 4) + 1;
                    //if the square is open available the doodle bug will 
                    // make a move into that square
                    if (randNumb == 1 && row < maxRows-1 && board[row + 1][column] == NULL) {
                        makeMoveD(row, column, 1, 0, food);
                    }
                    else if (randNumb == 2 && row > 0 && board[row - 1][column] == NULL) {
                        makeMoveD(row, column, -1, 0, food);
                    }
                    else if (randNumb == 3 && column < maxColumns-1 && board[row][column + 1] == NULL) {
                        makeMoveD(row, column, 0, 1, food);
                    }
                   else if (randNumb == 4 && column > 0 && board[row][column - 1] == NULL) {
                        makeMoveD(row, column, 0, -1, food);
                    }
                } 
            }
        }
    }

    for (int row = 0; row < maxRows; row++) {
        for (int column = 0; column < maxColumns; column++) {
            if (dynamic_cast <Ant*> (board[row][column])) {

                int randNumb = (rand() % 4) + 1;
                //increment the age of the ant
                board[row][column]->incrementAge();
                //makes a random move based on the randNumb generated
                // square must be equal to null to make move.
                    if (randNumb == 1 && row < maxRows - 1 &&
                    board[row + 1][column] == NULL) {
                        makeMoveA(row, column, 1, 0);
                    }
                    else if (randNumb == 2 && row > 0 &&
                    board[row - 1][column] == NULL) {
                        makeMoveA(row, column, -1, 0);
                    }
                    else if (randNumb == 3 && column < maxColumns-1 &&
                    board[row][column + 1] == NULL) {
                        makeMoveA(row, column, 0, 1);
                    }
                   else if (randNumb == 4 && column > 0 &&
                   board[row][column - 1] == NULL) {
                        makeMoveA(row, column, 0, -1);
                    }
                }
	}
    }
}

/*****************************************************************************   
** Description: The makeMoveA function moves the ant in a random direction
** parameters: current row, current column, row to increment, column to increment
** return: none                                                                  
*****************************************************************************/
void Simulation::makeMoveA(int row, int column, int i, int j) {
    
    //checks if next move is valid
   	if (validMove(row + i, column + j )) {
        //copy critter pointer to new position
        board[row + i][column + j] = board[row][column];
                 
   	    //remove criter from previous position
   	    removeCritter(row + i,column + j);
    }
}

/*****************************************************************************   
** Description: The validMoveA function checks the square the ant will move into
against the constrains of the board size
** parameters: current row, current column, row to increment, column to increment
** return: none                                                                  
*****************************************************************************/
bool Simulation::validMove(int row, int col) {

   if(row < 0) {  
    	return false;
	}
    else if(row == maxRows) {
        return false;
    }     

    else if(col < 0) {  
        return false;
    }
    
    else if(col == maxColumns) {
        return false;
    }
	else {
		return true;
	}
} 

/*****************************************************************************   
** Description: The makeMoveD function moves the doodlebug based on whether the ant
moved to a square with an Ant or there was no ant, if there was no ant in an
adjacent square the doodlebug makes a random move. The function then checks when 
the doodlebug last ate, and if it's last meal was 3 or more move prior the doodlebug
starves and it is removed from the board
** parameters: current row, current column, row to increment, column to increment
** if the doodlebug moved to an ant position (true/fasle)
** return: none                                                                  
*****************************************************************************/
void Simulation::makeMoveD(int row, int column, int i, int j, bool eat) {
    if (eat) {
             //remove Ant in row and column
             removeCritter(row + i, column + j);
                   
             //feed Doodlebug use reset last meal
             dynamic_cast <Doodlebug*>(board[row][column])->resetLastMeal();
                   
             //copy critter pointer to new position
             board[row + i][column + j] = board[row][column];
                   
             //remove criter from previous position
             removeCritter(row,column);
    }
    else {
    	if (validMove(row + i, column + j)) {
    		//copy critter pointer to new position
       	    board[row + i][column + j] = board[row][column];
                  
          	//remove criter from previous position
           	removeCritter(row,column);

            }
	    
		//increment last meal
		static_cast <Doodlebug*> (board[row + i][column + j])->
	    incrementLastMeal();
	    // if the doodle bug has not eaten in 3 moves it dies 
	    // and the removecritter function is called
		if (static_cast <Doodlebug*> (board[row + i][column + j])->
	    getLastMeal() >= 3) {
		removeCritter(row + i, column + j);
	    }
    }
}

void Simulation::addCritter(int row, int col, string critterType)
{
    //board[row][col] = new Critter;
    //get a random number to pick direction
    int moveRand = getRandNum(1,4);
    bool successfulBreed = false;
    int attemptsLeft = 4;
    
    //loop until 
    while(attemptsLeft > 0 && !successfulBreed) {
    	if(moveRand == 1) {
    		//check is west is within board
    		if (col - 1 >= 0) {
    			//check if west is null
    			if (board[row][col - 1] != NULL) {
    				//BREED depending on type
    				if (critterType == "ANT") {
    					board[row][col - 1] = new Ant;
    				}
    				else {
    					board[row][col - 1] = new Doodlebug;
    				}
    				successfulBreed = true;
    			}
    			else{
    				//otherwise, update attempt 
    				moveRand++;
    			}
    		}
    	}
    	else if (moveRand == 2) {
    		//check is North is within board
    		if (row - 1 >= 0) {
    			//check if north is null
    			if (board[row - 1][col] != NULL) {
    				//BREED depending on type
    				if (critterType == "ANT") {
    					board[row - 1][col] = new Ant;
    				}
    				else {
    					board[row - 1][col] = new Doodlebug;
    				}
    				successfulBreed = true;
    			}
    			else{
    				//otherwise, update attempt 
    				moveRand++;
    			}
    		}	
    	}
    	else if (moveRand == 3) {
    		//check is east is within board
    		if (col + 1 <= maxColumns) {
    			//check if east is null
    			if (board[row][col + 1] != NULL) {
    				//BREED depending on type
    				if (critterType == "ANT") {
    					board[row][col + 1] = new Ant;
    				}
    				else {
    					board[row][col + 1]= new Doodlebug;
    				}
    				successfulBreed = true;
    			}
    			else{
    				//otherwise, update attempt 
    				moveRand++;
    			}
    		}	
    	}
    	else {
    		//check is south is within board
    		if (row + 1 <= maxRows) {
    			//check if south is null
    			if (board[row + 1][col] != NULL) {
    				//BREED depending on type
    				if (critterType == "ANT") {
    					board[row + 1][col] = new Ant;
    				}
    				else {
    					board[row + 1][col]= new Doodlebug;
    				}
    				successfulBreed = true;
    			}
    			else{
    				//otherwise, update attempt 
    				moveRand = 1;
    			}
    		}	
    	}
    	//decrement attempts Left
    	attemptsLeft--;
    }
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
			//check for NULL first
			if (board[row][column] != NULL) {
				if (dynamic_cast<Ant*>(board[row][column])) {
					//then check age
					if(board[row][column]->getAge() % 3) {
						//attempt to breed. 
						addCritter(row, column, "ANT");      
					}
				}
				
				else if (dynamic_cast<Doodlebug*>(board[row][column])) {
					//then check age
					if(board[row][column]->getAge() % 8) {
						//attempt to breed. 
						addCritter(row, column, "DOODLEBUG");   
					}
				}
			}
				
		}
	}
}


/*****************************************************************************
** Description:	starve function checks the last time fed on doodlebugs on the 
* board. If == 3, doodlebug killed and removed from board
** parameters: none
** return: none
* 
* 
* 
* I think we delete this whole thing after Eric's implementation within Move?!?!?!?!?
* 
* 
*****************************************************************************/
void Simulation::starve() {/*
	//iterate through board
	for (int row = 0; row < maxRows; row++) {
		for (int column = 0; column < maxColumns; column++) {
			//ERRORS  if (typeid(board[row][column]) == typeid(Doodlebug)) {
				//check for last meal and delete
				//if (static_cast<*Doodlebug>(board[row][col])->getLastMeal() == 3) {
					//kill doodlebug
					//removeCritter(row, column);
				//}
			//}
		}
	}

*/
}
