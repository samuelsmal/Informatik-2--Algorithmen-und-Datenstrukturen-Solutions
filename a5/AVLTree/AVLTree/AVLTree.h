//
//  AVLTree.h
//  AVLTree
//
//  Created by Samuel von Bausznern on 29.04.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __AVLTree__AVLTree__
#define __AVLTree__AVLTree__

#include <iostream>

#include "AVLTreeNode.h"

template <class T> class AVLTree {
private:
    AVLTreeNode<T>* root;
    
    void addNodeToTree(T value, AVLTreeNode* currentNode) {
        if (value < currentNode->value()) {
            if (currentNode->leftChild()) {
                addNodeToTree(value, currentNode->leftChild());
            } else {
                currentNode->leftChild(new AVLTreeNode(value, currentNode));
                this->rebalance(currentNode);
            }
        } else {
            if (currentNode->rightChild()) {
                addNodeToTree(value, currentNode->rightChild());
            } else {
                currentNode->rightChild(new AVLTreeNode(value, currentNode));
                this->rebalance(currentNode);
            }
        }
    }
    
    void rebalance(AVLTreeNode& currentNode) {
        int bal = currentNode->balance();
                
        if (bal == -2) {
            int rightChildBalance = currentNode->rightChild->balance();
            switch (rightChildBalance) {
                case  0:
                case -1:
                    // single left rotation
                    leftRotation(currentNode);
                    break;
                    
                default:
                    // first: right rotation
                    rightRotation(currentNode);
                    // second: left rotation
                    leftRotation(currentNode);
                    break;
            }
        } if (bal == 2) {
            int leftChildBalance = currentNode->leftChild()->balance();
        }
        
        if (currentNode->parent()) rebalance(currentNode->parent());
    }
    
    void leftRotation(AVLTreeNode& node) {
        AVLTreeNode* currentParent = node->parent();
        currentParent->rightChild(node->leftChild());
        node->leftChild(currentParent);
        
        if (root != currentParent) {
            node->parent(currentParent->parent());
        } else {
            root = node;
            node->parent(nullptr);
        }
    }
    
    void rightRotation(AVLTreeNode& node) {
        AVLTreeNode* currentParent = node->parent();
        currentParent->leftChild(node->rightChild());
        node->parent(currentParent->parent());
        // unfinished;
        
        
    }
    
public:
    AVLTree<T>() : root(nullptr){};
    AVLTree<T>(T value) {
        root = new AVLTreeNode<T>(value, nullptr);
    };
    ~AVLTree<T>() {
        delete root;
    };
    
    AVLTree<T>& addNode(T value) {
        if (!root) {
            root = new AVLTreeNode<T>(value, nullptr);
        } else {
            this->addNodeToTree(value, root);
        }
        
        return this;
    };
};

#endif /* defined(__AVLTree__AVLTree__) */
