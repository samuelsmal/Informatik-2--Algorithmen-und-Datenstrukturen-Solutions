#include <iostream>
#include <cassert>

#include "DoublyLinkedList.hpp" 

// standard constructor
DoublyLinkedList::DoublyLinkedList ()
    : head( 0 )
    , tail( 0 )
{}

DoublyLinkedListNode* DoublyLinkedList::get_head() {
    return head;
}

DoublyLinkedListNode* DoublyLinkedList::get_tail() {
    return tail;
}


// i find the design pattern really weird. why separate the functionality?
void DoublyLinkedList::push_front(double value) {
    DoublyLinkedListNode *new_node = new DoublyLinkedListNode(value);
    
    if (is_empty()) {
        head = tail = new_node;
    } else {
        head->insert_as_previous_node(new_node);
        head = new_node;
    }
}


// i find the design pattern really weird. why separate the functionality?
void DoublyLinkedList::push_back(double value) {
    DoublyLinkedListNode *new_node = new DoublyLinkedListNode(value);
    
    if (is_empty()) {
        head = tail = new_node;
    } else {
        tail->insert_as_next_node(new_node);
        tail = new_node;
    }
}


void DoublyLinkedList::pop_front() {
    if (!is_empty()) {
        if (head == tail) {
            head = tail = 0;
        } else {
            DoublyLinkedListNode *n = head->get_next();
            if (n) n->set_prev(0);
            head = n;
        }
    }
    
    // instead of if (!is_empty()) i could use an assert.
    // note that cassert is deprecated.
    // note further that it's use wouldn't make much sense:
    //  the controll function of an if-statement is necessary, since we never check for something like "head->has_next()".

}

// delete node from back of list
void DoublyLinkedList::pop_back() {
    if (!is_empty()) {
        if (head == tail) {
            head = tail = 0;
        } else {
            DoublyLinkedListNode *n = tail->get_prev();
            if (n) n->set_next(0);
            if (n == head) head = n;
            tail = n;
        }
    }
}

bool DoublyLinkedList::is_empty() {
    return (head && tail) ? false : true;
}

void DoublyLinkedList::print_list() {
    if (is_empty()) {
        std::cout << "the list is empty\n";
    } else {
        DoublyLinkedListNode *traf = head;
        do {
            std::cout << traf->get_value() << "\n";
            traf = traf->get_next();
        } while (traf);
    }
}