/*
Q6. Find the diameter (longest path between any two nodes) of a binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
    int diameter = 0;
public:
    int height(Node* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        diameter = max(diameter, l + r);
        return 1 + max(l, r);
    }

    int findDiameter(Node* root) {
        height(root);
        return diameter;
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
        cout << "Diameter of tree: " << findDiameter(root) << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
