#include "dijkstra.hpp"
#include "loadFile.hpp"
#include "print.hpp"
#include "bfs.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    LoadFile load;
    Dijkstra dijkstra;
    print printValues;

    LoadFile::Map map = load.loadFile("grid.txt");
    std::cout << "Rows: " << map.rows << ", Cols: " << map.colums << std::endl;
    auto adj = load.createGraph(map);

    if (map.initialPosition == -1 || map.endPosition == -1)
    {
        std::cerr << "Error: Start (S) or End (T) not found in grid." << std::endl;
        std::cerr << "Start: " << map.initialPosition << ", End: " << map.endPosition << std::endl;
        return 1;
    }

    Dijkstra::ResultadoDijkstra res = dijkstra.dijkstra(adj, map.initialPosition);

    if (res.distancias[map.endPosition] == INT_MAX)
    {
        std::cout << "No se encontró un camino." << std::endl;
        std::cout << "Iteraciones realizadas: " << res.iterations << std::endl;
        return 0;
    }

    std::vector<int> camino;
    int actual = map.endPosition;

    while (actual != -1)
    {
        camino.push_back(actual);
        actual = res.padres[actual];
    }

    std::reverse(camino.begin(), camino.end());

    for (int nodoID : camino)
    {
        printValues.printGraph(nodoID, map.colums, map.grid);
        std::cout << "----------------------------------------------------------------------------------------------------\n" << std::endl;
    }

    BFS bfsMain;
    BFS::resultBFS resBFS = bfsMain.bfs(adj, map.initialPosition);

    if (resBFS.distance[map.endPosition] == INT_MAX)
    {
        std::cout << "BFS: No se encontró un camino." << std::endl;
    }
    else
    {
        std::cout << "\n--- Dijkstra ---" << std::endl;
        std::cout << "Costo del camino: " << res.distancias[map.endPosition] << std::endl;
        std::cout << "Iteraciones realizadas: " << res.iterations << std::endl;
        std::cout << "\n--- BFS ---" << std::endl;
        std::cout << "Costo del camino: " << resBFS.distance[map.endPosition] << std::endl;
        std::cout << "Iteraciones realizadas: " << resBFS.iteraction << std::endl;
    }

    return 0;
}