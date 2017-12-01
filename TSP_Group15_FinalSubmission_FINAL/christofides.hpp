/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#ifndef CHRISTOFIDES_HPP
#define CHRISTOFIDES_HPP

#include "edge.hpp"
#include <vector>
using std::vector;

// Class that defines the steps/facts 
// for the Christofides algorithm 

vector<vector<Edge> > MST(vector<vector<int> >& edgeMatrix);

int findMin(vector<int>& key); 

vector<int> vertOddDegree(vector<vector<Edge> >& adjList);

void minMatch(vector<vector<Edge> >& graph, vector<int>& oddVertices, vector<vector<int> > em);

vector<int> matchToEuler (vector<vector<Edge> >& graph, int start);

vector<int> hamilton (vector<int> eulerTour, int numOfCities);

#endif

 