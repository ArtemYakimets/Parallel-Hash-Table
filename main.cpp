#include <iostream>
#include <omp.h>
#include "hash_table.h"

using namespace htb;

int main() {
    double start_time, end_time;
    int max_threads = omp_get_max_threads();

    std::cout << "Insert" << std::endl;

    for (int t = 0; t < max_threads; t++) {
        HashTable hash_table = HashTable();
        start_time = omp_get_wtime();

        #pragma omp parallel num_threads(t) default(shared)
        {
            #pragma omp for
            for (int i = 0; i < 1000000; i++) {
                hash_table.insert(i, 123);
            }
        }

        end_time = omp_get_wtime();
        std::cout << "Threads: " << t + 1 << " Time elapsed to insert: " << (end_time - start_time) << " seconds" << std::endl;
    }

    HashTable hash_table = HashTable();
    for (int i = 0; i < 1000000; i++) {
        hash_table.insert(i, 123);
    }

    std::cout << "Search" << std::endl;

    for (int t = 0; t < max_threads; t++) {
        start_time = omp_get_wtime();

        #pragma omp parallel num_threads(t) default(shared)
        {
            #pragma omp for
            for (int i = 0; i < 1000000; i++) {
                std::cout << i << std::endl;
                hash_table.search(i);
            }
        }

        end_time = omp_get_wtime();
        std::cout << "Threads: " << t + 1 << " Time elapsed to search: " << (end_time - start_time) << " seconds" << std::endl;
    }

    return 0;
}