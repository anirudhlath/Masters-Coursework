//
// Created by Anirudh Lath on 3/23/22.
//

#ifndef ASSIGNMENT04_HASHTABLE_H
#define ASSIGNMENT04_HASHTABLE_H

#include <cstdio>

class HashNode {
public:
    void *ptr;
    size_t size;

    HashNode(void *ptr, size_t size) {
        this->ptr = ptr;
        this->size = size;
    }

    HashNode() {
        this->size = NULL;
        this->ptr = nullptr;
    }

};

class HashTable {
private:

    void grow();
    int hashCode(void *ptr);

public:
    HashTable();
    bool insert(void *ptr, size_t memSize);
    bool remove(void *ptr);
    size_t search(void *ptr);
    int length();
    ~HashTable();

    int capacity;
    int size;
    HashNode *table;
};

#endif //ASSIGNMENT04_HASHTABLE_H
