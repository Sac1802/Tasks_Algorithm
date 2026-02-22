#include "loadFile.hpp"

LoadFile::Map LoadFile::loadFile(std::string route)
{
    LoadFile::Map map;
    map.initialPosition = -1;
    map.endPosition = -1;
    std::ifstream file(route);
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        std::string row = "";
        for (int i = 0; i < line.size(); i += 3)
        {
            if (i < line.size())
                row += line[i + 1];
        }
        map.grid.push_back(row);
    }

    map.rows = map.grid.size();
    map.colums = map.grid.empty() ? 0 : map.grid[0].size();
    return map;
}

std::vector<std::vector<std::pair<int, int>>> LoadFile::createGraph(LoadFile::Map &map)
{
    int V = map.rows * map.colums;
    std::vector<std::vector<std::pair<int, int>>> adj(V);

    for (int i = 0; i < map.rows; i++)
    {
        for (int j = 0; j < map.colums; j++)
        {
            if (map.grid[i][j] == '#')
                continue;

            int currentId = i * map.colums + j;

            if (map.grid[i][j] == 'S') {
                map.initialPosition = currentId;
            }
            if (map.grid[i][j] == 'T') {
                map.endPosition = currentId;
            }

            validateNeighbor(adj, map, currentId);
        }
    }
    return adj;
}

void LoadFile::validateNeighbor(std::vector<std::vector<std::pair<int, int>>> &adj, Map &map, int currentId)
{
    int row = currentId / map.colums;
    int col = currentId % map.colums;

    for (int i = 0; i < 4; i++)
    {
        int nRow = row + dirRow[i];
        int nCol = col + dirCol[i];

        if (nRow >= 0 && nRow < map.rows && nCol >= 0 && nCol < map.colums)
        {
            if (map.grid[nRow][nCol] != '#')
            {
                int neighborId = nRow * map.colums + nCol;
                adj[currentId].push_back({neighborId, 1});
            }
        }
    }
}