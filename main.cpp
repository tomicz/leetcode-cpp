#include <iostream>
#include <chrono>
#include "includes/binary_tree.h"

int main(){
    BinaryTree* binary_tree = new BinaryTree(50);
    binary_tree->insert(30);
    binary_tree->insert(20);
    binary_tree->insert(8);
    binary_tree->insert(1);
    binary_tree->insert(51);
    binary_tree->insert(53);
    binary_tree->insert(80);
    binary_tree->insert(70);
    std::cout << "max depth: " << binary_tree->max_depth() << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
