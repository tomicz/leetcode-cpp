
### 110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

### Example 1

  3
 / \
9   20 
   /  \
  15   7

Input: root = [3,9,20,null,null,15,7]
Output: true]

### Example 2

      1
     / \
    2   2
   / \
  3   3
 / \
4   4

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

### Example 3 

Input: root = []
Output: true

### Example 4

      1
     / \
    2   2
   /     \
  3       3
 /         \
4           4

Input: [1,2,2,3,null,null,3,4,null,null,4]
Output: false

### Constraints

- The number of nodes in the tree is in the range [0, 5000].
- 104 <= Node.val <= 104

### How to compile
    g++ -std=c++17 -o main main.cpp ../../includes/binary_tree.cpp

### How to run
    ./main
