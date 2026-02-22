# Pathfinding: Shortest Path from S to T

## Overview
This project solves the classic problem of finding the optimal (lowest cost) path between a starting point (`S`) and a target destination (`T`) on a 2D grid map. The map comprises passable terrain (represented by `.`) and impassable walls or obstacles (represented by `#`).

The program determines the shortest route by modeling the grid map as a graph and applying graph search algorithms to compute the best possible path while minimizing the cost.

## How the Problem is Solved

### 1. Graph Construction
Before pathfinding begins, the program reads the grid layout from a text file (such as `grid.txt`). It translates the 2D grid into an **Adjacency List** graph structure:
- **Nodes/Vertices:** Every non-obstacle character (`.`, `S`, `T`) is converted into a node in the graph.
- **Edges:** Connections are established between adjacent traversable nodes (up, down, left, and right).
- **Obstacles:** Any walls (`#`) are ignored, meaning no edges will connect to or pass through them.

### 2. Best Path Calculation (Dijkstra's Algorithm)
To guarantee the lowest cost path from Start to Target, the program implements **Dijkstra's Algorithm**.
- It initializes the distance of the starting node `S` to 0 and all other nodes to infinity.
- Utilizing a Priority Queue, it continuously explores the unvisited neighbor with the current lowest accumulated cost.
- Every time a shorter path to a neighbor is found, its distance is updated, and the "parent" node is recorded to allow path reconstruction later.
- Because all edge weights in this standard grid are uniform (cost of 1 per step), Dijkstra expands outward systematically. Once `T` is reached, the path is guaranteed to be the most optimal route.
- Finally, the algorithm backtracks from `T` using the parent nodes to build and display the exact sequence of steps required to reach the target.

### 3. Algorithm Comparison (BFS)
In addition to Dijkstra, the program also executes a **Breadth-First Search (BFS)** algorithm. In an unweighted grid, BFS is also capable of finding the shortest path and can serve as a baseline to compare efficiency. The program tracks and outputs the number of **iterations** each algorithm took to reach the target, allowing you to compare their performance side-by-side.

## Program Output
When executed, the program performs the following:
1. Loads the grid and displays its dimensions (Rows and Columns).
2. Uses Dijkstra to determine the best path.
3. Visually prints the grid multiple times, showing the step-by-step progress of the path from `S` to `T`.
4. Outputs a final performance comparison:
   - **Path Cost** (number of steps).
   - **Iterations Performed** by both Dijkstra's Algorithm and BFS.

## Compilation and Execution

To compile and run the project, use a C++ compiler (supporting C++11 or higher). Assuming you use `g++`, you can run the following commands from the project root:

```bash
# Compile the main file and all source files in the src/ directory
g++ main.cpp src/*.cpp -I include -o programa

# Run the compiled executable
./programa
```
