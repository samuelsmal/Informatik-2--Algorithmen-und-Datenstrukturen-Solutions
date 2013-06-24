//
//  AVLTreeNode.h
//  AVLTree
//
//  Created by Samuel von Bausznern on 29.04.13.
//  Copyright (c) 2013 Samuel von Bausznern. All rights reserved.
//

#ifndef __AVLTree__AVLTreeNode__
#define __AVLTree__AVLTreeNode__

#include <iostream>


// The implementation of a template class has to be in the .h-file.
// Otherwise the compiler cannot create the class for the given type.
// Including the .cpp-file is not a solution, it's a workaround.
template <class T> class AVLTreeNode {
private:
    AVLTreeNode* _parent;
    AVLTreeNode* _leftChild;
    AVLTreeNode* _rightChild;
    
    T _value;
    
public:
    AVLTreeNode(T value,
                AVLTreeNode* parent,
                AVLTreeNode* leftChild = nullptr,
                AVLTreeNode* rightChild = nullptr) :
        _value(value), _parent(parent), _leftChild(leftChild), _rightChild(rightChild)
    {};
    ~AVLTreeNode() {
        if (_leftChild) delete _leftChild;
        if (_rightChild) delete _rightChild;
        delete this;
    };

    
    const AVLTreeNode& parent() const { return *_parent; };
    AVLTreeNode& parent(const AVLTreeNode& parent) {
        _parent = &parent;
        return *_parent;
    };
    
    const AVLTreeNode& leftChild() const { return *_leftChild; };
    AVLTreeNode& leftChild(const AVLTreeNode& child) {
        _leftChild = &child;
        return *_leftChild;
    };
    
    const AVLTreeNode& rightChild() const { return *_rightChild; };
    AVLTreeNode& rightChild(const AVLTreeNode& child){
        _rightChild = &child;
        return *_rightChild;
    };

    int getHeight() const {
        int leftmax = (_leftChild != nullptr) ? _leftChild->getHeight() + 1 : 0;
        int rightmax = (_rightChild != nullptr) ? _rightChild->getHeight() + 1 : 0;
        
        return leftmax > rightmax ? leftmax : rightmax;
    };

    bool isBalanced() const {
        int b = this->balance();
        return (-1 <= b && b <= 1);
    };
    
    int balance() const {
        int left = _leftChild ? _leftChild->getHeight() : 0;
        int right = _rightChild ? _rightChild->getHeight() : 0;
        return left - right;
    };
    
    
    T value() const { return _value; };
    void value(T value) { _value = value; };

};

#endif /* defined(__AVLTree__AVLTreeNode__) */
