/*
Q10. Find the maximum path sum in a binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
    int maxSum = INT_MIN;
public:
    int maxPath(Node* root) {
        if (!root) return 0;
        int l = max(0, maxPath(root->left));
        int r = max(0, maxPath(root->right));
        maxSum = max(maxSum, l + r + root->val);
        return root->val + max(l, r);
    }

    int findMaxPath(Node* root) {
        maxPath(root);
        return maxSum;
    }

    Node* buildTree() {
        Node* root = new Node(-10);
        root->left = new Node(9);
        root->right = new Node(20);
        root->right->left = new Node(15);
        root->right->right = new Node(7);
        return root;
    }

    void solve() {
        Node* root = buildTree();
        cout << "Maximum Path Sum: " << findMaxPath(root) << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
