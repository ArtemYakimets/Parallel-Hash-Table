#pragma once

#define TABLE_SIZE 10

namespace htb {

class Node {
public:
    int key;
    int value;
    Node *next;

    Node(const int key, const int value);

    ~Node();
};

class HashTable {
private:
    Node *buckets[TABLE_SIZE];

    unsigned int hash(const int key);

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
