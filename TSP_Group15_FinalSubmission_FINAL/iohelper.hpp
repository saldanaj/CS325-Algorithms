/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#ifndef IOHELPER_HPP
#define IOHELPER_HPP

#include "city.hpp"
#include <string>
#include <vector>
using std::vector;
using std::string;

/*
Functions to read file and to write out to file ending in .tour 
*/ 

vector<City*> readInput(string);

void writeOutput(string, vector<int>, int);

int tourDistance(vector<int>& tour, vector<vector<int> > &em);

#endif

