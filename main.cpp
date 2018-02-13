#include <iostream>
#include <cstdlib>
#include <ctime>
#include "simulation.hpp"
using std::cout;
using std::endl;

int main()
{
	//seed generation	
	int seed = time(0);
	srand(seed);

	//welcome user
	cout << endl << "		Welcome to the predator-prey simulation!" 
	     << endl << endl;
	cout << "Extra Credit: user chooses board size and critter spawns" << endl;
	//create game object
	Simulation game;

	//run the game
	game.run();

	//exit
	cout << "Goodbye" << endl;
	return 0;
}
