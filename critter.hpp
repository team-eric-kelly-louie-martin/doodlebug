
#ifndef CRITTER_HPP
#define CRITTER_HPP	

class Critter 
{
	protected:
		int age;

	public:
		//constructors & destructors
		Critter();
		virtual ~Critter();
		
		//getters
		int getAge();
		virtual int getLastMeal() = 0;

		//misc.	
        	virtual void incrementLastMeal() = 0;
		virtual void resetLastMeal() = 0;
		void incrementAge();
};

class Doodlebug : public Critter
{
	private:
		int lastMeal;

	public:
		//constructors & destructors
		Doodlebug();
		virtual ~Doodlebug();
		
		//getters
		int getLastMeal();

		//misc.
		void incrementLastMeal();
		void resetLastMeal();
};

class Ant : public Critter
{
	public:
		//constructors & destructors
		Ant();
		virtual ~Ant();
};

#endif
