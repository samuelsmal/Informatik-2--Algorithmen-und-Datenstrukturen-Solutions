//
//  eulertour.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//

#include "graph.h"
#include <iostream>

using namespace std;

void print_graph(graph* newGraph);
int eulertour(graph* eulergraph);
void createCircle(graph* myGraph);

static int MAX_NODES = 5;


int main(){
    
    graph myGraph;
    
    // create Nodes and add them to the graph
    for(int i=0; i<MAX_NODES; i++){
        node* temp = new node(i);
        myGraph.add_node(temp);
    }
    
    
                
    // creates edges between nodes
    createCircle(&myGraph);
    
    print_graph(&myGraph);
    
    int result = eulertour(&myGraph);
    
    if(result > 0){
        cout<<"Euler path found"<<endl;
    }
    else {
        cout<<"no euler"<<endl;
    }
    
    return 0;
}

void print_graph(graph* newGraph){    
    for (std::vector<node*>::const_iterator n_it = newGraph->get_nodes().begin();
         n_it != newGraph->get_nodes().end(); ++n_it)
    {
        node* current_node = *n_it;
        std::cout << "Edges Node " << current_node->get_id();
        
        for (std::vector<edge*>::const_iterator e_it = current_node->get_edges().begin();
             e_it != current_node->get_edges().end();
             ++e_it)
        {
            std::cout << "\n" << current_node->get_id() << "-->" << (*e_it)->getn2().get_id();
        }
        std::cout << std::endl;
    }

}

void createCircle(graph* myGraph){
    node* temp1 = myGraph->get_nodes().at(0); // and temp1 is needed for what? only needed for the last edge! where temp2 could have been used!
    node* temp2 = myGraph->get_nodes().at(1);
    myGraph->get_nodes().at(0)->add_edge(temp2);

    
    temp1 = myGraph->get_nodes().at(1);
    temp2 = myGraph->get_nodes().at(2);
    myGraph->get_nodes().at(1)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(2);
    temp2 = myGraph->get_nodes().at(3);
    myGraph->get_nodes().at(2)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(3);
    temp2 = myGraph->get_nodes().at(4);
    myGraph->get_nodes().at(3)->add_edge(temp2);
    
    temp1 = myGraph->get_nodes().at(0);
    temp2 = myGraph->get_nodes().at(4);
    myGraph->get_nodes().at(4)->add_edge(temp1);
}

int eulertour(graph* eulergraph){
    bool has_one_special_in = false; // more in than out
    bool has_one_special_out = false;// more out than in
    
    const int size = eulergraph->get_nodes().size(); // should use size_type
    
    int number_of_nodes[size][2]; // [.][0]: in, [.][1]: out
    for (int k = 0; k < size; k++) {
        number_of_nodes[k][0] = number_of_nodes[k][1] = 0;
    }
    
    // calculates the number of in and out edges.
    int i = 0;
    for (std::vector<node*>::const_iterator n_it = eulergraph->get_nodes().begin(); n_it != eulergraph->get_nodes().end(); ++n_it) {
        number_of_nodes[i][1] = (*n_it)->get_edges().size();
        node* current_node = *n_it;
        
        std::cout << "current node address " << *n_it << std::endl;
        
        /*
        for (std::vector<edge*>::const_iterator e_it = current_node->get_edges().begin(); e_it != current_node->get_edges().end(); ++e_it) {
            number_of_nodes[(*e_it)->getn2().get_id()][0]++;
        }
        */
    }
    
    // checks the condition:
    // for every node except max two: in - out = 0.
    // for the two others: in - out = 1 for one, and the other out - in = 1.
    for (int k = 0; k < size; k++) {
        int checksum = number_of_nodes[k][0] - number_of_nodes[k][1];
        if (checksum != 0) {
            if (checksum > 0) {
                if (has_one_special_in) {
                    return -1;
                } else {
                    has_one_special_in = true;
                }
            } else {
                if (has_one_special_out) {
                    return -1;
                } else {
                    has_one_special_out = true;
                }
            }
        }
    }
    
    
    return 1;
}



