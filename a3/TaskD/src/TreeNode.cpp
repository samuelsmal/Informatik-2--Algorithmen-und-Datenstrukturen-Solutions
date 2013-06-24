/*
 Assignment 3 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */


#include <iostream>
#include <string>
#include "TreeNode.h"
#include "KeyValuePair.h"


TreeNode::TreeNode(KeyValuePair element_){
    element = &element_;
    left_child = NULL;
    right_child = NULL;
}



TreeNode::TreeNode(int key_, std::string value_){
    
    KeyValuePair* tmp_element = new KeyValuePair(key_, value_);
    element = tmp_element;
    left_child = NULL;
    right_child = NULL;
}


KeyValuePair* TreeNode::getPair(){
    return element;
}


void TreeNode::setLeftChild(TreeNode* node_pointer_){
    left_child = node_pointer_;
}

void TreeNode::setRightChild(TreeNode* node_pointer_){
    right_child = node_pointer_;
}


void TreeNode::printPreOrder(){
    std::cout << "Key:\t" << this->element->getKey() << "\tValue:\t"<< this->element->getValue() << "\n";
    if (left_child) {
        left_child->printPreOrder();
    }
    if (right_child) {
        right_child->printPreOrder();
    }
}



void TreeNode::printInOrder(){
    
    if (left_child) {
        left_child->printPreOrder();
    }
    std::cout << "Key:\t" << this->element->getKey() << "\tValue:\t"<< this->element->getValue() << "\n";
    if (right_child) {
        right_child->printPreOrder();
    }
    
}



void TreeNode::printPostOrder(){
    
    if (left_child) {
        left_child->printPreOrder();
    }
    if (right_child) {
        right_child->printPreOrder();
    }
    std::cout << "Key:\t" << this->element->getKey() << "\tValue:\t" << this->element->getValue() << "\n";
}



TreeNode* TreeNode::searchKey(int key_){
    if (element->getKey() == key_) {
        return this;
    } else if (element->getKey() > key_) {
        if (left_child) {
            return left_child->searchKey(key_);
        } else {
            std::cout << "no such key, but here's the closest parent\n"; // throw exception here.
            return this;
        }
        
    } else {
        if (right_child) {
            return right_child->searchKey(key_);
        } else {
            std::cout << "no such key, but here's the closest parent\n"; // throw exception here.
            return this;
        }
    }
}



void TreeNode::add(KeyValuePair* element_){
    TreeNode *closestNode = searchKey(element_->getKey());
    
    if (closestNode->getPair()->getKey() == element_->getKey()) {
        // what now? overriding the existing node?
        std::cout << "an element with this key already exists!\n";
    } else if (closestNode->getPair()->getKey() > element_->getKey()) {
        closestNode->setLeftChild(new TreeNode(element_->getKey(), element_->getValue()));
    } else {
        closestNode->setRightChild(new TreeNode(element_->getKey(), element_->getValue()));
    }
}

