#include "print.hpp"

void print::printGraph(int nodeId, int totalColums, std::vector<std::string> grid)
{
    int ro = nodeId / totalColums;
    int col = nodeId % totalColums;

    if (grid[ro][col] != 'S' && grid[ro][col] != 'T')
        grid[ro][col] = 'O';

    for (const auto &row : grid)
    {
        std::cout << row << std::endl;
    }
}