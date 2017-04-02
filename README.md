# extra8
Simple C++ program illustrating binary trees and their properties.

## My Code School

### Binary Tree Traversal
* Breadth-first [YouTube Link](https://youtu.be/86g8jAQug04)
  * Level-order
* Depth-first [YouTube link](https://www.youtube.com/watch?v=gm8DUJJhmY4)
  * Preorder
    * \<root\>\<left\>\<right\>
  * Inorder
    * \<left\>\<root\>\<right\>
  * Postorder
    * \<left\>\<right\>\<root\>
  * Time Complexity
    * All of the algorithms are O(n)
  * Space Complexity
    * O(h) where h is the height of the tree
      * Worst case: O(n)
      * Best/Average case: O(log n)

__Preorder - Algorithm__
  * Visit root
  * Visit left subtree
  * Visit right subtree

__Inorder- Algorithm__
  * Visit left subtree
  * Visit root
  * Visit right subtree

__Postorder - Algorithm__
  * Visit left subtree
  * Visit right subtree
  * Visit root

### Check if a Given Binary Tree is a Binary Search Tree
* Binary Search Tree
  * A binary tree in which for each node the value of all the nodes in left subtree is lesser or equal and value of all the nodes in right subtree is greater.