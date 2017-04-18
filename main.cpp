#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
    int data = 0;
    node *left = 0;
    node *right = 0;
};

node* getNewNode(int data) {
    node *newNode = new node();
    newNode->data = data;
    newNode->left = 0;
    newNode->right = 0;
    return newNode;
}

node* insert(node *root, int data) {
    if (root == nullptr) { //if tree is empty
        root = getNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(node *root, int data) {
    if (root == nullptr) {
        return false;
    }
    else if (root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

node* find_min(node *root) { //Smaller number will always be to the left
    if (root == nullptr) {
        return nullptr;
    }
    while(root->left != NULL)  {
        root = root->left;
    }
	return root;
}

int find_max(node *root) { //Larger number will always be to the right
    if(root == nullptr) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if(root->right == nullptr) {
        return root->data;
    }
    return find_max(root->right);
}

int find_height(node *root) { /*Defines height as counting the number of edges in the longest path of a tree
    To implement height as the number of nodes in the longest path of a tree need to return 0 instead of -1*/
    if(root == nullptr) {
        return -1;
    }
    return max(find_height(root->left), find_height(root->right)) + 1;
}

void print(list<int> & mylist) {
    cout << "\ttree contains:";
    for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
}

void levelorder(node *root) {
    if (root == nullptr) {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *current = q.front();
        cout << current->data << " ";
        if(current->left != nullptr) {
            q.push(current->left);
        }
        if(current->right != nullptr) {
            q.push(current->right);
        }
        q.pop();
    }
}

void preorder(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool is_bst_util(node *root, int min, int max) { //return true if BST, false otherwise
    if(root == nullptr) {
        return true;
    }
    if(root->data > min && root->data <= max && is_bst_util(root->left, min, root->data) && is_bst_util(root->right, root->data, max)) {
        return true;
    }
    else {
        return false;
    }
}

bool is_bst(node *root) {
    return is_bst_util(root, INT_MIN, INT_MAX);
}

node* deletenode(node* root, int data) {
    if (root == nullptr) {
        return root; //Can also return NULL
    }
    else if (data < root->data) {
        root->left = deletenode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deletenode(root->right, data);
    }
    else { //Found the right, will now be deleted
        //Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root; //Deallocate memory of an object from heap
            root = nullptr; //root is a dangling pointer so set root to NULL to mitigate
        }
        //Case 2: One child
        else if (root->left == nullptr) {
            node *temp = root; //Store address of current node trying to delete in temp pointer
            root = root->right; //Move root to right child
            delete temp;
        }
        else if (root->right == nullptr) {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        //Case 3: 2 children
        else {
            node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    return root;
}

node* find(node *root, int data) {
    if (root == nullptr) {
        return nullptr;
    }
    else if (root->data == data) {
        return root;
    }
    else if (root->data < data) {
        return find(root->right, data);
    }
    else {
        return find(root->left, data);
    }
}

node* getsuccessor(node *root, int data) {
    // Search the node - O(h)
    node *current = find(root, data);
    if (current == nullptr) {
        return nullptr;
    }
    // Case 1: Node has right subtree
    if (current->right != nullptr) {
        return find_min(current->right);
    }
    // Case 2: No right subtree - O(h)
    else {
        node *successor = nullptr;
        node *ancestor = root;
        while (ancestor != current) {
            if (current->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main(int argc, char * argv[]) {
    node *root = 0;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 25);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, 16);
    root = insert(root, 27);
    
    node *temp = find_min(root);
    cout << "\tMinimum: " << temp->data << endl;
    cout << "\tMaximum: " << find_max(root) << endl;
    cout << "\tHeight: " << find_height(root) << endl;
    cout << endl;

    int number;
    if(is_bst(root) == true) {
        cout << "\tYes, BST" << endl;
        cout << endl;
    }
    else {
        cout << "\tNot BST" << endl;
        cout << endl;        
    }

    cout << "\tLevelorder: ";
    levelorder(root);
    cout << endl;
    cout << "\tPreorder: ";
    preorder(root);
    cout << endl;
    cout << "\tInorder: ";
    inorder(root);
    cout << endl;
    cout << "\tPostorder: ";
    postorder(root);
    cout << endl;

    node *successor = getsuccessor(root, 10);
    if (successor == nullptr) {
        cout << "\tNo successor found\n";
    }
    else {
        cout << "\tSuccessor of 10 is: " << successor->data << endl;
    }
    cout << endl;

    cout << "\tDelete 15: ";
    deletenode(root, 15);
    cout << endl;
    cout << "\tLevelorder: ";
    levelorder(root);
    cout << endl;

    return 0;
}