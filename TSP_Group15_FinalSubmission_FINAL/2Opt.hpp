/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#ifndef TWOOPT_HPP
#define TWOOPT_HPP

#include <vector>
#include <string>
#include <ctime>
#include <limits>
using std::vector;
using std::string;

/*
The 2-opt class that uses the swap function and calculates the 
distance of 2 edges 
*/ 

void twoOptSwap(vector<int>& tour, int index1, int index2);

vector<int> twoOpt(vector<int>& tour, vector<vector<int> > &em, int initialDistance, clock_t start, string outputFilename);

int twoOptDist(vector<int>& tour, int i, int j, vector<vector<int> >& em, int distance);

#endif