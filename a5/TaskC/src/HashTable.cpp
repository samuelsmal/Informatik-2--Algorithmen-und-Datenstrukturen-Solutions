/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#include <iostream>
#include <cmath>
#include "math.h"
#include "HashTable.h"



HashTable::HashTable(){
    table = new Item*[TABLE_SIZE];
    
    //Using MAD compression map, therefore we need factors a and b
    factor_a = 7;
    factor_b = 13;
}

int HashTable::hashfunction(int key_){
    int index = (factor_a * key_  + factor_b) % TABLE_SIZE;  //compute the hash of the key using MAD compression (see slides)
    return index;
}

void HashTable::put(Item* item){
    int probe = hashfunction(item->getKey());
    
    for (int j = 1; table[probe] != 0; j++) {
        probe++;
        probe %= TABLE_SIZE;
        
        if (j == TABLE_SIZE) {
            std::cout << "TABLE IS FULL!";
            return;
        }
    }
    
    table[probe] = item;
}

Item* HashTable::get(int key_){
    int probe = hashfunction(key_);
    
    for (int j = 0; j < TABLE_SIZE; j++) {
        probe++;
        probe %= TABLE_SIZE;
        if ((table[probe] != 0) && (table[probe]->getKey() == key_)) {
            return table[probe];
        }
    }
    
    
    std::cout << "KEY NOT IN TABLE!";
    return NULL;
}

void HashTable::putQuadratic(Item* item){
    int probe = hashfunction(item->getKey());
    
    for (int j = 0; table[probe] != 0; j++) {
        probe += j*j;
        probe %= TABLE_SIZE;
        
        if (j + 1 == TABLE_SIZE) {
            std::cout << "TABLE IS FULL!";
            return;
        }
    }
    
    table[probe] = item;

}

Item* HashTable::getQuadratic(int key_){
    int probe = hashfunction(key_);
    
    for (int i = 0, j = 0; j < TABLE_SIZE; i++, j++) {
        probe += i*i;
        probe %= TABLE_SIZE;
        if ((table[probe] != 0) && (table[probe]->getKey() == key_)) {
            return table[probe];
        }
    }
    
    std::cout << "KEY NOT IN TABLE!";
    return NULL;

}

void HashTable::printContent(){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) {
            std::cout << i << "\t | \t" << "NULL" << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }else{
            std::cout << i << "\t | \t" <<  table[i]->getName() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}

