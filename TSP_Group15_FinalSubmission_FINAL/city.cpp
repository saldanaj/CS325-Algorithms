/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

// city class 
// simple mutator and accessor methods 

#include "city.hpp"
#include <stdio.h>
#include <math.h>

City::City() 
{
	id = -1;
}

City::City(int id, int x, int y) 
{
	this->id = id;
	this->x = x;
	this->y = y;
}

// get the city id 
int City::getID() 
{
	return id;
}

// get city's x coordinate 
int City::getX() 
{
	return x;
}

// get city's y coordinate 
int City::getY() 
{
	return y;
}

// using run slope formula to calculate distance between both 
// vertices 
double City::distance(City b) 
{
	double xDiffSq = pow((this->getX() - b.getX()), 2);
	
	double yDiffSq = pow((this->getY() - b.getY()), 2);

	double dist = round(sqrt(xDiffSq + yDiffSq));
	
	return dist;
}

// mutator method for city id 
void City::setID(int id) 
{
	this->id = id;
}

// mutator method for city x-coordinate
void City::setX(int x) 
{
	this->x = x;
}

// mutator method for city y-coordinate
void City::setY(int y) 
{
	this->y = y;
}