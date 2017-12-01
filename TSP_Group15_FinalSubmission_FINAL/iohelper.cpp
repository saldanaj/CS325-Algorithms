/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 


#include "iohelper.hpp"
#include "city.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
using std::getline;
using std::stringstream;

/* 
 Read input from file and create a city object and store it in the vector 
 */
vector<City*> readInput(string inputFilename) 
{
	ifstream inputFD;

	inputFD.open(inputFilename.c_str());

	vector<City*> cities;

	string line;


	if (inputFD.is_open()) 
	{
		int id, x, y;

		while (getline(inputFD, line))
		{
			stringstream ss(line);
		
			ss >> id >> x >> y;
			
			City *city = new City(id, x, y);
			
			cities.push_back(city);
		}	
		
		inputFD.close();

	}
	
	return cities;
}

/*
Open and create the output file, writing the total tour length in the 
first lin and writting to the file the paths taken 
 */
void writeOutput(string outputFilename, vector<int> cities, int distance) 
{
	
	ofstream outputFD (outputFilename.c_str());

	if (outputFD.is_open()) {
		
		outputFD << distance << endl;
		
		for (int i = 0; i < cities.size(); i++) {
			outputFD << cities[i] << endl;
		}
		
		outputFD.close();
	}
}

/* 
Calculate the TSP distance 
 */
int tourDistance(vector<int>& tour, vector<vector<int> > &em) 
{
	int distance = 0;
	
	for (int i = 0; i < tour.size() - 1; i++) 
	{
		distance += em[tour[i]][tour[i + 1]];
	}
	
	distance += em[tour[0]][tour.back()];
	
	return distance;
}
