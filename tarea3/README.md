# Zoomba - Robot Traversal Simulator

This project is a C++ implementation that simulates the traversal of a "Zoomba" robot across a 2D map. The robot uses two different search algorithms to explore the map: Breadth-First Search (BFS) and Depth-First Search (DFS).

## Features

- **Map Representation**: Maps are created from a string representation, where:
  - `S`: Is the robot's starting point.
  - `+`: Cleared/dirty floor.
  - `.`: Cleared/clean floor.
  - `#`: Furniture / wall.
- **Search Algorithms**:
  - **BFS (Breadth-First Search)**: The robot explores the map level by level.
  - **DFS (Depth-First Search)**: The robot explores the map as far as possible along one branch before backtracking.
- **Traversal Visualization**: The program prints the map's state to the console at each step the robot takes, marking the path traversed.
- **Energy Calculation**: The total "energy" consumed in each traversal is calculated and displayed, which corresponds to the number of cells visited.

## File Structure

- `main.cpp`: Contains the main function that initializes the test maps and runs the BFS and DFS simulations.
- `zoomba.hpp`: Contains the declaration of the `zoomba` class, which encapsulates all the logic and data for the robot and the map.
- `zoomba.cpp`: Contains the implementation of the `zoomba` class methods.

## How to Compile and Run

You can compile the project using a C++ compiler like g++.

1. **Compile the code:**
   Open a terminal and run the following command to compile all `.cpp` files:

   ```sh
   g++ main.cpp zoomba.cpp -o zoomba_simulation
   ```

2. **Run the simulation:**
   Once compiled, you can run the program with the following command:

   ```sh
   ./zoomba_simulation
   ```

The program will run simulations on three example maps (small, medium, and complex) and display the traversal and energy consumed for each one.