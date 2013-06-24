//
//  AVL_Tree.h
//  AVL_Tree
//
//  Created by Samuel von Bausznern on 06.05.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __AVL_Tree__AVL_Tree__
#define __AVL_Tree__AVL_Tree__

#include <iostream>

class Node {

public:
    int key;        // just for making it easier. a template would be nice.
    Node *left;
    Node *right;
    Node *parent;
    int balanceFactor;
};

class AVL_Tree {
private:
    Node *root;
    
    void roateL
    
public:
    AVL_Tree();
    ~AVL_Tree();
    
AVL_Tree& insert(int value);


    
};

#endif /* defined(__AVL_Tree__AVL_Tree__) */
