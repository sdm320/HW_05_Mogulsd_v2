//Code modified from Cooper Riley
//http://www.technical-recipes.com/2012/genetic-algorithms-applied-to-travelling-saleman-problems-in-c/
//http://apostvav.wordpress.com/2011/04/14/brute-force-search-tsp/
//http://www.codeproject.com/Articles/1403/Genetic-Algorithms-and-the-Traveling-Salesman-Prob
#include "GraphAlgs.h"
#include "StarbucksMap.h"

int* bestPath;
float bestPathLength;
double currDist;
Graph* currentGraph;
void tour(int* arr, int size, int start);
void swap(int* arr, int first, int second);

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	currentGraph = G;
	currDist = 0.0;
	EdgeWeight tourDist = 0;

	int num_nodes = G -> size();
	std::vector<NodeID> bestTourNodes (num_nodes);
	bestPath = new int[num_nodes];

	for(int i = 0; i < num_nodes; i++){
		bestPath[i] = i;  
	}
	bestPathLength = 0;   
	for(int i = 0; i < num_nodes - 1; i++){                     
		bestPathLength += currentGraph -> weight(bestPath[i], bestPath[i+1]); 
	}
	tourDist += currentGraph -> weight(bestPath[num_nodes-1], bestPath[0]);
	tour(bestPath, num_nodes, 0);
	for(int i = 0; i < num_nodes; i++){
		bestTourNodes[i] = bestPath[i];
	}

	std::pair<std::vector<NodeID>, EdgeWeight> finalTour(bestTourNodes, bestPathLength);

	return finalTour;
}

//code from lecture 11/20
void tour(int* arr, int size, int startingPoint){
	if(size - startingPoint == 1){
		EdgeWeight tourDist = 0;
	for(int i = 0; i < size - 1; i++){                     
		tourDist += currentGraph -> weight(arr[i], arr[i+1]); 
	}
	tourDist += currentGraph -> weight(arr[size-1], arr[0]);
		if(currDist < bestPathLength){
			for(int i = 0; i < size; i++){
				bestPath[i] = arr[i];  
			}
			bestPathLength = currDist;
		}
	} else {
		for(int i = startingPoint; i < size; i++){
			swap(arr, startingPoint, i);
			tour(arr, size, startingPoint + 1);
			swap(arr, startingPoint, i);
		}
	}
}



void swap(int* arr, int first, int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp; arr;
}