#include <cstdio>
#include <iostream>
#include <list>

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


private:
    node *root = 0;
    
};

void print(list<char> & mylist) {
    cout << "\ttree contains:";
    for (list<char>::iterator it = mylist.begin(); it != mylist.end(); ++it) {
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
    // preorder();
    list<char> mylist;
    tree a;
    mylist.push_back('A');
    mylist.push_back('B');
    mylist.push_back('C');
    mylist.push_back('D');

    print(mylist);
    // a.print(mylist);
    
    cout << endl;
    return 0;
}