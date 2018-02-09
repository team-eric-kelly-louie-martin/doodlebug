
#ifndef CRITTER_HPP
#define CRITTER_HPP	

class Critter 
{
	protected:
		int rowPos,
		    colPos,
		    age;

	public:
		//constructors & destructors
		Critter(int rowPos, int colPos, int age = 0);
		~Critter();	
	
		//getters
		int getAge();
		int getRow();
		int getCol();

		//misc.	
		virtual void move() = 0;
		void ageUp();

};

class Doodlebug : public Critter
{
	private:
		int lastMeal;

	public:
		//constructors & destructors
		Doodlebug(int rowPos, int colPos, int lastMeal = 0);
		~Doodlebug() {};
		
		//getters
		int getLastMeal();

		//misc.
		void move();
};

class Ant : public Critter
{
	private:

	public:
		//constructors & destructors
		Ant(int rowPos, int colPos);
		~Ant() {};

		//misc.
		void move();
};

#endif
