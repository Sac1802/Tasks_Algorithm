#include <iostream>
#include "zoomba.hpp"

int main()
{
    zoomba z;

    std::cout << "========== MAP 1 (Small) ==========\n";
    z.insertInGraph("S++/#++/+++");
    std::cout << "----- BFS -----\n";
    z.moveAndValidateBFS();

    z.insertInGraph("S++/#++/+++");
    std::cout << "----- DFS -----\n";
    z.moveAndValidateDFS();


    std::cout << "\n========== MAP 2 (half) ==========\n";
    z.insertInGraph("S+++#/#+#++/++++#/++#++");
    std::cout << "----- BFS -----\n";
    z.moveAndValidateBFS();

    z.insertInGraph("S+++#/#+#++/++++#/++#++");
    std::cout << "----- DFS -----\n";
    z.moveAndValidateDFS();


    std::cout << "\n========== MAP 3 (Complex) ==========\n";
    z.insertInGraph("S++#++#/#+#+++#/++#+++#/#+#++++");
    std::cout << "----- BFS -----\n";
    z.moveAndValidateBFS();

    z.insertInGraph("S++#++#/#+#+++#/++#+++#/#+#++++");
    std::cout << "----- DFS -----\n";
    z.moveAndValidateDFS();

    return 0;
}
