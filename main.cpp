#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

struct node {
    int data = ' ';
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
    
    int number;
    cout << "Enter number to be searched\n";
    cin >> number;
    if(search(root, number) == true) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }

    return 0;
}