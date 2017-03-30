#include <cstdio>
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

struct node {
    char data = ' ';
    node *left = 0;
    node *right = 0;
};

class tree {
public:
    tree(){}

    ~tree(){}

    // void print(list<tree> const & list) {
    //     node *temp = root;
    //     for (int i = 0; i < list.size(); i++) {
    //         cout << temp->data << endl;
    //         temp = temp->left;
    //     }
    // }

private:
    node *root = 0;
    
};

void preorder(node *root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


int main(int argc, char * argv[]) {
    // preorder();
    list<char> tree;
    ostream_iterator<int> screen(cout, " ");
    tree.push_back('A');
    copy(tree.begin(), tree.end(), screen);
    cout << endl;
    return 0;
}