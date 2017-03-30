# extra8
Simple C++ program illustrating preorder, inorder, and postorder traversals of trees

## My Code School Tree Traversals
[YouTube link](https://www.youtube.com/watch?v=gm8DUJJhmY4)

### Binary Tree Traversal
* Breadth-first
  * Level-order
* Depth-first
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