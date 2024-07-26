# BST Explorer in C++

## Overview

`bst-explorer-cpp` is a simple C++ implementation of a Binary Search Tree (BST). This repository provides a basic BST with functionalities to insert, remove, and print nodes in a post-order traversal. It includes a command-line interface for easy interaction and visualization of the tree structure.

## Features

- **Insertion**: Add new nodes to the BST.
- **Removal**: Delete nodes from the BST.
- **Post-Order Printing**: Visualize the BST structure using post-order traversal.

## Getting Started

### Prerequisites

To compile and run the code, you need:

- A C++ compiler (e.g., g++, clang++)
- C++11 or later

### Compilation

To compile the code, navigate to the directory containing `main.cpp` and run:

    g++ -std=c++11 -o bst_explorer main.cpp

### Running the Program

After compilation, you can run the program using:

    ./bst_explorer

You will see a menu with the following options:

1. **Insertion/Creation**: Insert a new value into the BST.
2. **Printing**: Print the BST in post-order traversal.
3. **Removal**: Remove a node from the BST.
4. **Exit**: Exit the program.

### Example

Here's how you can interact with the program:

    Binary Search Tree Operations 
    ----------------------------- 
    1. Insertion/Creation 
    2. Printing 
    3. Removal 
    4. Exit 
    Enter your choice : 1
    Enter Number to be inserted : 10

    Binary Search Tree Operations 
    ----------------------------- 
    1. Insertion/Creation 
    2. Printing 
    3. Removal 
    4. Exit 
    Enter your choice : 2

    Printing 
    --------------------
    R----10

## Code Explanation

- **BinarySearchTree Class**: Contains methods for insertion, removal, and printing of the BST.
  - `insert(int value)`: Adds a new value to the BST.
  - `remove(int value)`: Removes a value from the BST.
  - `printPostOrder()`: Prints the BST using post-order traversal.

- **TreeNode Struct**: Represents a node in the BST with pointers to left and right children and a data value.

- **postOrder(TreeNode*, int, bool)**: Helper function for printing the BST in a post-order manner.

## Contributing

Feel free to fork this repository and submit pull requests with improvements or fixes. For any issues or feature requests, please open an issue on GitHub.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact

If you have any questions or suggestions, feel free to reach out to me at pratirathgupta51@gmail.com

---

Happy coding!

Brought by,
Pratirath Gupta
