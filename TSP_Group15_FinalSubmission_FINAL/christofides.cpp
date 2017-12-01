/*
CS325 / Group 15 
Students: Jordan Gilman, Lauren Spiegel, Joaquin Saldana 
*/ 

/*
Christofides class that brings together the MST, the Eulor functions 
the Hamiltonian function
*/ 

#include "christofides.hpp"
#include "edge.hpp"
#include <vector>
#include <stack>
#include <limits>
using std::vector;
using std::stack;
using std::numeric_limits;


/*
Function to find the minimum spanning tree 
Returns an adjancency edge list 
*/ 
vector<vector<Edge> > MST(vector<vector<int> >& edgeMatrix) 
{
	int numOfCities = edgeMatrix.size();

	vector<vector<Edge> > adjList;

	adjList.resize(numOfCities);

	vector<int> key(numOfCities, numeric_limits<int>::max());

	vector<int> parent(numOfCities);

	key[0] = 0;

	parent[0] = 0;

	for (int i = 0; i < numOfCities; i++) 
	{
	
		int min = findMin(key);
	
		key[min] = -1;
	
		for (int j = 0; j < numOfCities; j++) 
		{
			if (key[j] != -1 && edgeMatrix[min][j] < key[j]) 
			{
				key[j] = edgeMatrix[min][j];
				parent[j] = min;
			}
		}
	}
	
	for (int i = 1; i < numOfCities; i++) 
	{
		int vertex1 = i;
	
		int vertex2 = parent[i];
	
		int weight = edgeMatrix[vertex1][vertex2];
	
		adjList[vertex1].push_back(Edge(vertex1, vertex2, weight));
	
		adjList[vertex2].push_back(Edge(vertex2, vertex1, weight));
	}
	
	return adjList;
}

/*
findMin function that finds the edge with the smallest 
edge 
*/ 
int findMin(vector<int>& key) 
{
	int minIndex = -1;

	int min = numeric_limits<int>::max();

	for (int i = 0; i < key.size(); i++) 
	{
	
		if (key[i] > -1 && key[i] < min) 
		{
			minIndex = i;
			min = key[i];
		}
	}
	
	return minIndex;
}

/*
Find the vertices that contain an odd degree 
And return a vector which contains them 
*/ 
vector<int> vertOddDegree(vector<vector<Edge> >& adjList) 
{
	vector<int> oddVertices;

	for (int i = 0; i < adjList.size(); i++) 
	{
		if (adjList[i].size() % 2 == 1) 
		{
			oddVertices.push_back(i);
		}
	}

	return oddVertices;
}


/*
Find a match for the odd vertices, a small match 
*/ 

void minMatch(vector<vector<Edge> >& graph, vector<int>& oddVertices, vector<vector<int> > em) 
{
	int index = 0;

	for (int i = 0; i < oddVertices.size() / 2; i++) 
	{
		int curVertex = oddVertices[index];
	
		while (curVertex == -1) 
		{
			index++;
			curVertex = oddVertices[index];
		}

		int length = numeric_limits<int>::max();
		
		int nearestVert = -1;
		
		int nearVIndex;
		
		for (int j = 0; j < oddVertices.size(); j++) 
		{
			
			if (oddVertices[j] != -1 && j != index && em[curVertex][oddVertices[j]] < length) 
			{
				length = em[curVertex][oddVertices[j]];
				nearestVert = oddVertices[j];
				nearVIndex = j;
			}
		}
		
		oddVertices[index] = -1;
		
		oddVertices[nearVIndex] = -1;
		
		graph[curVertex].push_back(Edge(curVertex, nearestVert, length));
		
		graph[nearestVert].push_back(Edge(nearestVert, curVertex, length));
		
		index++;
	}
}

/*
Find the Eulor tour that uses the edges only once 
*/
vector<int> matchToEuler (vector<vector<Edge> >& graph, int start) 
{   
	stack<Edge> available; 	

	stack<int> curPath;		

	int numAvai, vertex2, vertex1 = start;

	vector<int> circuit; 	

	curPath.push(vertex1);	
	   
    do 
    {
    	do 
    	{
    		numAvai = 0; 


			for (int i = 0; i < graph[vertex1].size(); i++) 
			{
				if (!graph[vertex1][i].removed)
				{
					available.push(graph[vertex1][i]);

					numAvai++;
				}
			}

			if (numAvai == 0) 
			{

				circuit.push_back(vertex1);

				curPath.pop();


				if (!curPath.empty())
				{
					vertex1 = curPath.top();
				}
				else 
				{
					vertex1 = -5;
				}
			}

		} while (numAvai == 0 && !curPath.empty());

		if (vertex1 == -5) 
		{
			break;
		}

		else 
		{

			Edge* next = &available.top();

			available.pop();

			vertex2 = next->v2;

			curPath.push(vertex2);

		 	for(int x = 0; x < graph[vertex1].size(); x++) 
		 	{
		            if(graph[vertex1][x].v2 == vertex2) 
		            {
		                    graph[vertex1][x].removed = true; 
		            }
		    }

		    for(int y = 0; y < graph[vertex2].size(); y++) 
		    {
		            if(graph[vertex2][y].v2 == vertex1) 
		            {
		                    graph[vertex2][y].removed = true; 
		            }
		    }

		    vertex1 = vertex2;
		}	

    } while (!available.empty());


    vector<int> eulerTour;

    for (int i = circuit.size() - 1; i >= 0; i--) 
    {
    	eulerTour.push_back(circuit[i]);
    }

    return eulerTour;
}

/*
find the hamiltonian tour 
*/ 
vector<int> hamilton (vector<int> eulerTour, int numOfCities) 
{
	vector<int> initialTour;

	vector<bool> alreadySeen(numOfCities, 0);

	for (int i = 0; i < eulerTour.size(); i++) 
	{
		if (alreadySeen[eulerTour[i]] == 0) 
		{
			initialTour.push_back(eulerTour[i]);
			alreadySeen[eulerTour[i]] = 1;
		}
	}

	return initialTour;
}
