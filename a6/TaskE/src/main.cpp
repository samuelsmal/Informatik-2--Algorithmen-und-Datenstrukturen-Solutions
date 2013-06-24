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
#include <queue>
#include <climits>

#define nil INT_MIN
#define inf INT_MAX

typedef std::vector<int> VI; // to store the distances
typedef std::vector<VI> VVI; // to store an adjacency matrix

std::set<int> exploredNodes; // set of explored nodes (initially empty)

void BFS(VVI& graph, int v) {
    VI pred(graph.size());
    VI dist(graph.size());
    // setting the pred values for each node.
    // note that for an undirected array only the triangle-matrix (upper or lower) is needed.
    for (int i = 0; i < pred.size(); ++i) {
        for (int j = i; j < pred.size(); ++j) {
            pred[i] = nil;
            dist[i] = inf;
        }
    }
    dist[v] = 0;
    
    std::queue<int> nodes_to_visit;
    nodes_to_visit.push(v);
    
    int current_node;
    while (!nodes_to_visit.empty()) {
        current_node = nodes_to_visit.front();
        nodes_to_visit.pop();
        std::cout << current_node << " ";
        for (int i = 0; i < graph.size(); ++i) {
            if (graph[current_node][i]) {
                if (dist[i] == inf) {
                    dist[i] = dist[current_node] + 1;
                    pred[i] = current_node;
                    nodes_to_visit.push(i);
                    
                }
            }
        }
    }
}

int main() {
	VVI graph(9,VI(9,0)); // Create a graph with 9 nodes and no edges (empty adjacency matrix)

	// Add the undirected edges
	graph[0][1] = graph[1][0] = 1;
	graph[0][3] = graph[3][0] = 1;
	graph[1][2] = graph[2][1] = 1;
	graph[2][4] = graph[4][2] = 1;
	graph[3][2] = graph[2][3] = 1;
	graph[3][4] = graph[4][3] = 1;
	graph[3][6] = graph[6][3] = 1;
	graph[5][4] = graph[4][5] = 1;
	graph[6][5] = graph[5][6] = 1;
	graph[6][8] = graph[8][6] = 1;
	graph[7][3] = graph[3][7] = 1;
	graph[7][8] = graph[8][7] = 1;
	graph[8][5] = graph[5][8] = 1;

	// Do the BFS, starting at the first node
	BFS(graph,0);
}

