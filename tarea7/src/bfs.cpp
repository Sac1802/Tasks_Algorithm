#include "bfs.hpp"

BFS::resultBFS BFS::bfs(std::vector<std::vector<std::pair<int, int>>> &adj, int src){
    int V = adj.size();
    std::vector<int> dist(V, INT_MAX);
    std::vector<int> parent(V, -1);
    int iterationCount = 0;

    std::queue<int> q;
    dist[src] = 0;
    q.push(src);


    while(!q.empty()){
        iterationCount++;
        int u = q.front();
        q.pop();
        for(auto &p : adj[u]){
            int v = p.first;
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return {dist, parent, iterationCount};
}