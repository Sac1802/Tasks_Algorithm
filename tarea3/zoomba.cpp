#include "zoomba.hpp"

void zoomba::insertInGraph(std::string valuesInsert)
{
    std::vector<std::string> parts;
    std::stringstream ss(valuesInsert);
    std::string item;

    while (std::getline(ss, item, '/'))
    {
        parts.push_back(item);
    }
    int row = parts.size();
    int colum = parts[0].size();
    graph.clear();
    graph.resize(row, std::vector<char>(colum));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            graph[i][j] = parts[i][j];
            if (parts[i][j] == 'S')
                begin = {i, j};
        }
    }
}

void zoomba::printGraph(int r, int c)
{
    int row = graph.size();
    int column = graph[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (i == r && j == c)
                std::cout << "O ";
            else
                std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------\n";
}

std::vector<std::pair<int, int>> zoomba::searchNeighbors(std::pair<int, int> positionMachhine)
{
    int rowMachine = positionMachhine.first;
    int columnMachine = positionMachhine.second;
    int rows = graph.size();
    int cols = graph[0].size();

    std::vector<std::pair<int, int>> neighbors;

    std::vector<std::pair<int, int>> positions = {
        {rowMachine + 1, columnMachine},
        {rowMachine - 1, columnMachine},
        {rowMachine, columnMachine + 1},
        {rowMachine, columnMachine - 1}};

    for (std::pair<int, int> pos : positions)
    {
        int r = pos.first;
        int c = pos.second;

        if (r >= 0 && r < rows &&
            c >= 0 && c < cols &&
            graph[r][c] != '#' &&
            !visited[r][c])
        {
            visited[r][c] = true;
            neighbors.push_back(pos);
        }
    }
    return neighbors;
}

void zoomba::moveAndValidateBFS()
{
    visited.resize(graph.size(), std::vector<bool>(graph[0].size(), false));

    queues.push(begin);
    visited[begin.first][begin.second] = true;

    while (!queues.empty())
    {
        std::pair<int, int> current = queues.front();
        queues.pop();

        energy++;

        int r = current.first;
        int c = current.second;
        
        if(r == begin.first && c == begin.second) graph[r][c] = 'S';
        else graph[r][c] = '.';

        printGraph(r, c);
        std::vector<std::pair<int, int>> neighbors = searchNeighbors(current);
        for(std::pair<int, int> n: neighbors) queues.push(n);
    }

    std::cout << "Total energy used: " << energy << std::endl;
    reset();
}

void zoomba::moveAndValidateDFS(){
    visited.resize(graph.size(), std::vector<bool>(graph[0].size(), false));

    stacks.push(begin);
    visited[begin.first][begin.second] = true;

    while (!stacks.empty())
    {
        std::pair<int, int> current = stacks.top();
        stacks.pop();

        energy++;

        int r = current.first;
        int c = current.second;

        if(r == begin.first && c == begin.second) graph[r][c] = 'S';
        else graph[r][c] = '.';

        printGraph(r, c);
        std::vector<std::pair<int, int>> neighbors = searchNeighbors(current);
        for(std::pair<int, int> n: neighbors) stacks.push(n);
    }

    std::cout << "Total energy used: " << energy << std::endl;
    reset();
}

void zoomba::reset()
{
    energy = 0;
    visited.clear();
    while (!queues.empty())
        queues.pop();
    while (!stacks.empty())
        stacks.pop();
    
}
