/* 
Q1. Create a binary tree and perform inorder traversal.
   Input: Tree -> [1, 2, 3, null, 4]
   Output: [2, 4, 1, 3]
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    inorder(root);
}
