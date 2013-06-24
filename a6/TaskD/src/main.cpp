/*
  
 University of Zurich
 Department of Informatics
 Visualization and Multimedia Laboratory
 
 Author: Rafael Ballester
 Date: 12.04.2013
 */

#include <iostream>
#include <vector>
#include <set>
#include <list>

typedef std::vector<int> VI; // to store the distances
typedef std::vector<VI> VVI; // to store an adjacency matrix
typedef std::pair<int,int> PI; // to store an edge


std::set<int> exploredNodes; // set of explored nodes (initially empty)
std::set< PI > exploredEdges; // set of explored edges (initially empty)
std::set<int> marked;
std::list<int> topOrder;

void topologicalDFS(VVI& graph, int v) {
    if (marked.find(v) != marked.end()) {
        return;
    } else {
        marked.insert(v);
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[v][i]) {
                topologicalDFS(graph, i);
            }
        }
        exploredNodes.insert(v);
        topOrder.insert(topOrder.begin(), v);
    }
}

int main() {
	VVI graph(9,VI(9,0)); // Create a graph with 9 nodes and no edges (empty adjacency matrix)

	// Add the directed edges
	graph[0][1] = 1;
	graph[0][3] = 1;
	graph[1][2] = 1;
	graph[2][4] = 1;
	graph[3][2] = 1;
	graph[3][4] = 1;
	graph[3][6] = 1;
	graph[5][4] = 1;
	graph[6][5] = 1;
	graph[6][8] = 1;
	graph[7][3] = 1;
	graph[7][8] = 1;
	graph[8][5] = 1;

	// Do the topological DFS for every non-visited vertex
	for (int i = 0; i < graph.size(); ++i) {
		if (exploredNodes.find(i) == exploredNodes.end())
			topologicalDFS(graph,i);
	}
    
    for (std::list<int>::const_iterator itr = topOrder.begin(); itr != topOrder.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

