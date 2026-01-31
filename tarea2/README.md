# AVL vs. BST Performance Comparison

## Description

This project implements and compares the performance of two fundamental tree-based data structures: a standard Binary Search Tree (BST) and a self-balancing AVL Tree.

The program first populates both an AVL tree and a BST with 100,000 unique integers in a randomized order. It then measures and compares the average time taken to perform search operations on both structures. The searches are composed of a mix of values that exist within the trees and values that do not.

The goal is to empirically demonstrate the performance advantages of a balanced tree (AVL) over an unbalanced one (BST) for search operations, especially as the number of nodes grows.

## Data Structures

*   **Binary Search Tree (BST):** A simple node-based binary tree data structure which has the property that the value in a node is greater than all values in its left subtree and smaller than all values in its right subtree.
*   **AVL Tree:** A self-balancing binary search tree. It maintains a height balance factor for each node, performing rotations (restructuring) after insertions or deletions to ensure the tree remains balanced. This guarantees O(log n) time complexity for search, insertion, and deletion.

## Project Structure

The project is organized into the following directories:

-   `bin/`: Contains the compiled executable file.
-   `include/`: Contains the header files (`.hpp`) for the data structures.
-   `src/`: Contains the C++ source code files (`.cpp`).

## How to Compile and Run

1.  **Navigate to the project's root directory.**

2.  **Compile the source code:**
    Use the following `g++` command. This command compiles all the source files, uses the header files from the `include` directory, and places the final executable named `tarea2` into the `bin` directory.
    ```bash
    g++ -std=c++17 -Iinclude src/main.cpp src/bst.cpp src/avl.cpp -o bin/tarea2
    ```

3.  **Run the program:**
    Execute the compiled program from the root directory.
    ```bash
    ./bin/tarea2
    ```

You will see output comparing the average search times in nanoseconds for the BST and AVL tree.
