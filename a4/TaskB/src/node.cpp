//
//  node.cpp
//  EulerTour
//
//  Created by Fabian Hofstetter on 15.03.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "node.h"

node::node(int id_): _id(id_){
    
}

vector<edge*> node::get_edges(){
    return _edges;
}

void node::add_edge(node* newNode){
    struct edge* new_edge = new edge(this, newNode);
    _edges.push_back(new_edge);
}

int node::get_id(){
    return _id;
}

