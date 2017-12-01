/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#include "city.hpp"
#include "edge.hpp"
#include "iohelper.hpp"
#include "christofides.hpp"
#include "2Opt.hpp"

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stack>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::getline;


int main(int argc, char *argv[]) 
{
	clock_t start, stop;

	start = clock();

	double totalTime;

	// get file name entered on command line as arg 1 
	string inputFilename;
	if (argc > 1) 
	{
		inputFilename = argv[1];
	}
	else 
	{
		// error detection 
		cout << "Enter input filename: " << endl;
		getline(cin, inputFilename);
	}
	
	// create output name file 
	string outputFilename = inputFilename + ".tour";

	// read the input and store returned vector in cities variable 
	vector<City*> cities = readInput(inputFilename);

	// get total number of cities 
	// will need this for later to check 
	int numOfCities = cities.size();

	// create matrix of distance between all vertices 
	vector<vector<int> > edgeMatrix;

	edgeMatrix.resize(numOfCities, vector<int>(numOfCities, 0));
	
	for (int i = 0; i < edgeMatrix.size(); i++) 
	{ 
		// create edge matrix 
		for (int j = i; j < edgeMatrix[i].size(); j++) 
		{
			// distance from vertex to itself is 0
			if (j == i)
			{
				edgeMatrix[i][j] = 0;
			}
			else 
			{
				edgeMatrix[i][j] = (int)cities[i]->distance(*cities[j]);

				edgeMatrix[j][i] = edgeMatrix[i][j];
			}
		}
	} 

	// minimum spanning tree 
	vector<vector<Edge> > adjListMST = MST(edgeMatrix);

	// make sub graph 
	vector<int> odds = vertOddDegree(adjListMST); 
	
	// match odd vertices to create multigraph 
	minMatch(adjListMST, odds, edgeMatrix); 

	// find euler tour 
	vector<int> eulerTour = matchToEuler(adjListMST, adjListMST[0][0].v1);

	// find hamilton tour
	vector<int> hamiltonTour = hamilton(eulerTour, numOfCities);

	int hamiltonDistance = tourDistance(hamiltonTour, edgeMatrix);

	// run the 2opt function 
	vector<int> tour = twoOpt(hamiltonTour, edgeMatrix, hamiltonDistance, start, outputFilename);
	
	int finalDistance = tourDistance(tour, edgeMatrix);
	
	cout << "Tour Length: " << finalDistance << endl;

	// write TSP solution and tour of cities to the output file 
	writeOutput(outputFilename, tour, finalDistance);












	// save the total time it took to print out to console 
	stop = clock();
	
	totalTime = (double)(stop - start)/CLOCKS_PER_SEC;
	
	cout << "Total time: " << totalTime << " seconds" << endl;
}
