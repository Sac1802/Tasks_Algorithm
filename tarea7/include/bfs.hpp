#ifndef BDF_HPP
#define BDF_HPP

#include <vector>
#include <queue>
#include <climits>

class BFS
{
public:
    struct resultBFS
    {
        std::vector<int> distance;
        std::vector<int> parents;
        int iteraction;
    };
    resultBFS bfs(std::vector<std::vector<std::pair<int, int>>> &adj, int src);
};

#endif