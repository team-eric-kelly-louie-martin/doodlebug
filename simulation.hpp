
#ifndef SIMULATION_HPP
#define SIMULATION_HPP	

#include <vector>
#include "critter.hpp"
using std::vector;

class Simulation 
{
	private:
		Critter*** board;
		int maxSteps;
		int maxRows;
		int maxColumns;

	public:
		//constructors & destructors	
		Simulation();
		~Simulation();
		
		//misc.
		void run();
		void initialize();
		void breedEveryone();
		void starve();
		void addCritter(int row, int col);
		void removeCritter(int row, int col);
		void displayBoard();
        void move();
        bool validMove(int row, int col);
        void makeMoveD(int row, int column, int i, int j, bool eat);
        void makeMoveA(int row, int column, int i, int j);
};

#endif
