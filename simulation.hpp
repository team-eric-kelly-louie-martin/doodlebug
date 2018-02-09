
#ifndef SIMULATION_HPP
#define SIMULATION_HPP	

#include <vector>
#include "critter.hpp"
using std::vector;

class Simulation 
{
	private:
		char** board;
		int maxSteps;
		int maxRows;
		int maxColumns;

	public:
		//constructors & destructors	
		Simulation();
		~Simulation();
		
		//misc.
		void run();
		void breedEveryone();
		void Starve();
		void newCritter(int row, int col);
		void removeCritter(int row, int col);
		void displayBoard();

};

#endif
