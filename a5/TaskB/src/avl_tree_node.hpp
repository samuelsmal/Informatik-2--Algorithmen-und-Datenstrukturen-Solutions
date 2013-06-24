//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#ifndef _AVLTREENODE_HPP_
#define _AVLTREENODE_HPP_

#include <string>

class avl_tree;


class avl_tree_node {
    public:
        avl_tree_node(avl_tree* tree, int value) :
            _tree(tree), _value(value),
            _parent(NULL), _left(NULL), _right(NULL){};
    
        ~avl_tree_node() {delete _left; delete _right;};
        
        avl_tree_node* parent() const;
        avl_tree_node* left() const;
        avl_tree_node* right() const;
        
        void set_parent(avl_tree_node* parent);
        void set_left(avl_tree_node* left_child);
        void set_right(avl_tree_node* right_child);
        
        void insert(int value);
        
        bool is_balanced() const;
        int balance() const;
        int get_height() const;
        
        void restructure();

    private:
        avl_tree* _tree; // why on earth?
        
        int _value;
        
        avl_tree_node* _parent;
        avl_tree_node* _left;
        avl_tree_node* _right;
};

#endif // _AVLTREENODE_HPP_
