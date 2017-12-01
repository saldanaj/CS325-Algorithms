/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#include "2Opt.hpp"
#include <vector>
#include <string>
#include "iohelper.hpp"
#include <ctime>
#include <limits>

using std::vector;
using std::string;


/*
the 2opt swap funtion that swaps 2 edges 
*/ 
void twoOptSwap(vector<int>& tour, int index1, int index2) 
{
	int count = (index2 - index1) / 2;
	
	if (count == 0) 
	{
		count = 1;
	}
	
	for (int i = 0; i < count; i++) 
	{
		int temp = tour[index1];
	
		tour[index1] = tour[index2];
	
		tour[index2] = temp;
	
		index1++;
	
		index2--;
	}
}


/*
Funtion that optimizes the TSP solution by swapping edges 
*/ 
vector<int> twoOpt(vector<int>& tour, vector<vector<int> >& em, int initialDistance, clock_t start, string outputFilename) 
{
	vector<int> bestTour;
	
	int bestDistance = initialDistance;

	int found = 1;
	
	while (found > 0) 
	{
		found = 0;
	
		for (int i = 0; i < tour.size() - 1; i++) 
		{
			for (int j = i + 1; j < tour.size(); j++) 
			{
				if (double(clock() - start)/CLOCKS_PER_SEC > 175 && double(clock() - start) / CLOCKS_PER_SEC < 177) 
				{
					writeOutput(outputFilename, tour, bestDistance);
				}
				
				int newDistance = twoOptDist(tour, i, j, em, bestDistance);
				
				if (newDistance < bestDistance) 
				{
					bestDistance = newDistance;
				
					twoOptSwap(tour, i, j);
				
					found++;
				}
			}
		}
	}
	return tour;
}

/*
Calculate the distance of the tour between 2 edges 
*/ 

int twoOptDist(vector<int>& tour, int i, int j, vector<vector<int> >& em, int distance) 
{
	if (i == 0 && j == tour.size() - 1) 
	{
		return distance;
	}
	else if (i == 0) 
	{
		distance -= em[tour[j]][tour[j + 1]] + em[tour[i]][tour.back()];
		distance += em[tour[i]][tour[j + 1]] + em[tour[j]][tour.back()];
	}
	else if (j == tour.size() - 1) 
	{
		distance -= em[tour[i]][tour[i - 1]] + em[tour[j]][tour[0]];
		distance += em[tour[j]][tour[i - 1]] + em[tour[i]][tour[0]];
	}
	else 
	{
		distance -= em[tour[i]][tour[i - 1]] + em[tour[j]][tour[j + 1]];
		distance += em[tour[j]][tour[i - 1]] + em[tour[i]][tour[j + 1]];
	}
	
	return distance;
}