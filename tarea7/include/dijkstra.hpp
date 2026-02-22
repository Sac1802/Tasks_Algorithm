#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Dijkstra
{
public:
    struct ResultadoDijkstra
    {
        std::vector<int> ditances;
        std::vector<int> parents;
        int iterations;
    };
    ResultadoDijkstra dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj, int src);
};

#endif