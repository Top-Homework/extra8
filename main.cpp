#include <cstdio>
#include <iostream>
#include <list>
#include <algorithm>

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

int main(int argc, char * argv[]) {
    // list<int> mylist;
    // mylist.push_back(1);
    // mylist.push_back(2);
    // mylist.push_back(3);
    // mylist.push_back(4);

    // print(mylist);

    node *root = 0;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    
    cout << "\tMinimum: " << find_min(root) << endl;
    cout << "\tMaximum: " << find_max(root) << endl;
    cout << "\tHeight: " << find_height(root) << endl;

    // int number;
    // cout << "Enter number to be searched\n";
    // cin >> number;
    // if(search(root, number) == true) {
    //     cout << "Found\n";
    // }
    // else {
    //     cout << "Not Found\n";
    // }

    return 0;
}