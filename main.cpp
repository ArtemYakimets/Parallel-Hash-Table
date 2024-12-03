#include <iostream>
#include "hash_table.h"

using namespace htb;

int main() {

    HashTable hash_table = HashTable();
    hash_table.insert(5, 11);
    hash_table.insert(3, 12);
    hash_table.print();
    hash_table.remove(5);
    hash_table.print();

    return 0;
}