/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#ifndef CITY_HPP
#define CITY_HPP

// Simple city class 

class City 
{
	private:
		int id;
		int x;
		int y;

	public:
		City();
		City(int id, int x, int y);
		int getID(void);
		int getX(void);
		int getY(void);
		void setID(int);
		void setX(int);
		void setY(int);	
		double distance(City city);
};

#endif