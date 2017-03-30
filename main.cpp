#include <cstdio>
#include <iostream>

using namespace std;

struct node {
    char data;
    node *left;
    node *right;
};

void preorder(node *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char * argv[]) {
    preoder();
    return 0;
}