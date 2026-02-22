#include "dijkstra.hpp"

Dijkstra::ResultadoDijkstra Dijkstra::dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj, int src)
{
    int V = adj.size();
    std::vector<int> parent(V, -1);
    std::vector<int> dist(V, INT_MAX);
    int iterationCount = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty())
    {
        iterationCount++;

        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > dist[u])
            continue;

        for (auto &p : adj[u])
        {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    return {dist, parent, iterationCount};
}