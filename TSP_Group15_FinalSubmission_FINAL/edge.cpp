/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#include "edge.hpp"

// Construtor to create edges 
Edge::Edge(int v1, int v2, int weight) 
{
	this->v1 = v1;
	this->v2 = v2;
	this->weight = weight;
	this-> removed = false;
}