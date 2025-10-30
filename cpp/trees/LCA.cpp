/*
Q7. Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
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
    Node* LCA(Node* root, Node* p, Node* q) {
        if (!root || root == p || root == q) return root;
        Node* left = LCA(root->left, p, q);
        Node* right = LCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    Node* buildTree() {
        Node* root = new Node(3);
        root->left = new Node(5);
        root->right = new Node(1);
        root->left->left = new Node(6);
        root->left->right = new Node(2);
        root->right->left = new Node(0);
        root->right->right = new Node(8);
        return root;
    }

    void solve() {
        Node* root = buildTree();
        Node* p = root->left;           // 5
        Node* q = root->left->right;    // 2
        Node* ans = LCA(root, p, q);
        cout << "LCA of " << p->val << " and " << q->val << " is: " << ans->val << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
