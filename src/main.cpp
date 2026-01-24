#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "bst.hpp"
#include "avl.hpp"

int main()
{
    int N = 100000;
    avl avl;
    bst bst;

    std::vector<int> values;
    for (int i = 0; i < N; i++)
        values.push_back(i);

    std::shuffle(values.begin(), values.end(),
                 std::default_random_engine(std::random_device{}()));

    for (int v : values)
    {
        avl.insert(v);
        bst.insert(v);
    }

    int searches = 1000;
    long long totalAVL = 0;
    long long totalBST = 0;

    for (int i = 0; i < searches; i++)
    {
        int x;
        if (i < searches / 2)
        {
            // 50% EXISTENTES
            x = values[rand() % values.size()];
        }
        else
        {
            // 50% NO EXISTENTES
            x = N + rand();
        }

        // BST
        auto start = std::chrono::high_resolution_clock::now();
        bst.search(x);
        auto end = std::chrono::high_resolution_clock::now();
        totalBST += std::chrono::duration_cast<
                        std::chrono::nanoseconds>(end - start)
                        .count();

        // AVL
        start = std::chrono::high_resolution_clock::now();
        avl.search(x);
        end = std::chrono::high_resolution_clock::now();
        totalAVL += std::chrono::duration_cast<
                        std::chrono::nanoseconds>(end - start)
                        .count();
    }

    std::cout << "BST promedio: " << totalBST / searches << " ns\n";
    std::cout << "AVL promedio: " << totalAVL / searches << " ns\n";
}
