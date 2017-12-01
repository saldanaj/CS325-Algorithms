/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

#ifndef EDGE_HPP
#define EDGE_HPP

class Edge 
{
	public:
		Edge(int v1, int v2, int weight);
		int v1;
		int v2;
		int weight;
		bool removed;

};

#endif