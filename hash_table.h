#pragma once

#define TABLE_SIZE 10000
#define NUM_LOCKS 400

namespace htb {

class Node {
public:
    int key;
    int value;
    Node *next;

    Node(const int key, const int value);

    ~Node();
};

struct PaddedLock {
    omp_lock_t lock;
    char padding[64 - sizeof(omp_lock_t)]; 
};

class HashTable {
private:
    Node *buckets[TABLE_SIZE];
    PaddedLock locks[NUM_LOCKS];

    unsigned int hash(const int key);

    unsigned int lock_index(const int key);

    void clear();

public:
    HashTable();

    ~HashTable();

    void insert(const int key, const int value);

    int *search(const int key);

    void remove(const int key);

    void print();
};

}
