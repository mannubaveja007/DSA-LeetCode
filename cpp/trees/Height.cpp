/*
Q2. Find the height (maximum depth) of a binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    Node* buildTree() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        return root;
    }

    void solve() {
        Node* root = buildTree();
        cout << "Height of tree: " << height(root) << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
