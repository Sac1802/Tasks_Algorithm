#ifndef LOADFILE_HPP
#define LOADFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class LoadFile
{
public:
    struct Map
    {
        std::vector<std::string> grid;
        int rows;
        int colums;
        int initialPosition;
        int endPosition;
    };

private:
    int dirRow[4] = {-1, 1, 0, 0};
    int dirCol[4] = {0, 0, -1, 1};
    void validateNeighbor(std::vector<std::vector<std::pair<int, int>>> &adj, Map &map, int currentId);

public:
    Map loadFile(std::string route);
    std::vector<std::vector<std::pair<int, int>>> createGraph(Map &map);
};

#endif