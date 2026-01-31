#ifndef ZOOMBA_HPP
#define ZOOMBA_HPP

#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <utility>
#include <iostream>
#include <stack>

class zoomba
{
private:
    std::vector<std::vector<char>> graph;
    std::queue<std::pair<int, int>> queues;
    std::pair<int, int> begin;
    std::vector<std::vector<bool>> visited;
    std::stack<std::pair<int,int>> stacks;
    int energy = 0;
public:
    void insertInGraph(std::string valuesInsert);
    void printGraph(int row, int colum);
    std::vector<std::pair<int, int>> searchNeighbors(std::pair<int, int> positionMachhine);
    void moveAndValidateBFS();
    void moveAndValidateDFS();
    void reset();

};

#endif 