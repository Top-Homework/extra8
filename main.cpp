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

int find_min(node *root) { //Smaller number will always be to the left
    if(root == nullptr) {
        cout << "Error: Tree is empty\n";
        return -1;
    }
    else if(root->left == nullptr) {
        return root->data;
    }
    return find_min(root->left);
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

node* delete(node* root, int data) {
    
}

int main(int argc, char * argv[]) {
    // node *head = 0;
    // list<int> mylist;
    // head = mylist.push_back(1);
    // head = mylist.push_back(2);
    // head = mylist.push_back(3);
    // head = mylist.push_back(4);

    // print(mylist);

    node *root = 0;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    
    cout << "\tMinimum: " << find_min(root) << endl;
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

    // int number;
    // cout << "Enter number to be searched\n";
    // cin >> number;
    // if(search(root, number) == true) {
    //     cout << "Found\n";
    // }
    // else {
    //     cout << "Not Found\n";
    // }

    cout << "\tLevelorder: ";
    levelorder(root);
    cout << endl;
    cout << "\tPreorder: ";
    preorder(root);
    cout << endl;
    cout << "\tPostorder: ";
    postorder(root);
    cout << endl;

    return 0;
}