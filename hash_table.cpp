#include <iostream>
#include "hash_table.h"

namespace htb {

Node::Node(const int key, const int value) : key(key), value(value), next(nullptr) {}

Node::~Node() {}



unsigned int HashTable::hash(const int key) {
        return key % TABLE_SIZE;
    }

void HashTable::clear() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node *curr = buckets[i];
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        buckets[i] = nullptr;
    }
}

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        buckets[i] = nullptr;
    }
}

HashTable::~HashTable() {
    clear();
}

void HashTable::insert(const int key, const int value) {
    unsigned int index = hash(key);
    Node *new_node = new Node(key, value);

    if (!buckets[index]) {
        buckets[index] = new_node;
    } else {
        Node *curr = buckets[index];
        while (curr->next) {
            if (key == curr->key) {
                curr->value = value;
                delete new_node;
                return;
            }
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

int * HashTable::search(const int key) {
    int index = hash(key);

    Node *curr = buckets[index];
    
    while(curr) {
        if (curr->key == key) {
            return &curr->value;
        }
        curr = curr->next;
    }
    return nullptr;
}

void HashTable::remove(const int key) {
    unsigned int index = hash(key);
    Node *curr = buckets[index];
    Node *prev = nullptr;

    while (curr && (curr->key != key)) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        std::cout << "Key not found: " << key << std::endl;
        return;
    }

    if (prev) {
        prev->next = curr->next;
    } else {
        buckets[index] = curr->next;
    }
    delete curr;
}


void HashTable::print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        std::cout << "Bucket " << i << ": ";
        Node *curr = buckets[i];
        while (curr) {
            std::cout << "(" << curr->key << ", " << curr->value << ") -> ";
            curr = curr->next;
        }
        std::cout << "NULL" << std::endl;
    }
}

}
