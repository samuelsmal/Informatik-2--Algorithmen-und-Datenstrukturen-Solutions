//
//  node.h
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//



#ifndef EulerTour_node_h
#define EulerTour_node_h

#include <vector>
#include <iostream>

using namespace std;
struct edge;


class node {
public:
    node(int id_);
    
    vector<edge*> get_edges();
    void add_edge(node* newNode);
    int get_id();

    
private:
    vector<edge*> _edges; // why list of pointers? iterator becomes double pointer!
    int _id;
    
};

struct edge{
    node* node1;
    node* node2;
    
    bool visited;
    
    edge(node* n1, node* n2) : node1(n1), node2(n2){
        visited = false;
    }
    
    node getn1(){
        return *node1;
        // returns object! why?
        // why not pointer?
    }
    
    node getn2(){
        return *node2;
    }
};


#endif
