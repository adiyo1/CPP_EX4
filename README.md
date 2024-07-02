# Tree Visualization and Heap Conversion

## Overview

This project implements a tree data structure with multiple functionalities, including adding nodes, displaying the tree using a graphical interface (SFML), and converting the tree into a min-heap. The tree supports different data types, such as integers and complex numbers, and can handle binary and K-ary trees.

## Features

- **Tree Operations**: Add root and sub-nodes to build the tree structure.
- **Graphical Display**: Visualize the tree using the SFML library.
- **Min-Heap Conversion**: Convert the tree into a min-heap and iterate over the heap elements.
- **Custom Iterators**: Implement various iterators for traversing the tree (Pre-order, Post-order, In-order, DFS, BFS).

## Requirements

- C++17 or later
- SFML library for graphical display
- Makefile for building the project

## File Structure

- `Tree.hpp`: Defines the `Tree` class and its functionalities.
- `Node.hpp`: Defines the `Node` class.
- `Complex.hpp` and `Complex.cpp`: Defines the `Complex` class for complex number operations.
- `main.cpp`: Entry point of the application, demonstrating tree creation, manipulation, and display.
- `Makefile`: Script to build the project.
- `doctest.h`, `Test.cpp`, `TestCounter.cpp`: Files for unit testing using the doctest framework.

## Usage

### Building the Project

1. Ensure you have the SFML library installed.
2. Clean the project

    ```sh
    make clean
    ```

3. Run the executable:

    ```sh
    make tree
    ```

### Example

Here's an example of how to create a tree, add nodes, and display it:

```cpp
#include "Tree.hpp"
#include "Complex.hpp"

int main() {
    Tree<Complex, 3> tree;
    auto root_node = new Node<Complex>(Complex(1, 1));
    tree.add_root(root_node);

    auto n1 = new Node<Complex>(Complex(1, 2));
    auto n2 = new Node<Complex>(Complex(1, 3));
    auto n3 = new Node<Complex>(Complex(1, 4));
    auto n4 = new Node<Complex>(Complex(1, 5));
    auto n5 = new Node<Complex>(Complex(1, 6));
    auto n6 = new Node<Complex>(Complex(1, 7));

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
    tree.add_sub_node(n2, n6);

    tree.display();

    return 0;
}
