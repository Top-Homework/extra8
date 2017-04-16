# extra8
Simple C++ program illustrating binary trees and their properties.

## My Code School - Binary Search Tree

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

### Delete a Node from a Binary Search Tree
* [YouTube link](https://youtu.be/gcULXE7ViZw)
* COnsider 3 cases
  1. No child
    * Deleting a leaf node will not have an effect on the binary search tree
  2. One child
    * Deleting a node with one child has 2 different outcomes.
      * If deleting a node on the right side of the parent then connect parent with its only child and delete child from memory.
      * Repeat same process as above, but for left link
  3. 2 children
    * First approach is to reduce the case to either case 2 or case 1 for right link
      1. Find minimum in right-subtree
      2. Copy the value in targetted node
      3. Delete duplicate from right-subtree
    * Second approach is to reduce the case to either case 2 or case 1 for left link
      1. Find maximum in left-subtree
      2. Copy the value in targetted node
      3. Delete duplicate from left-subtree