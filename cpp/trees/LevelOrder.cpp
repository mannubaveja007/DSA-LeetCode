/*
Q4. Perform level order traversal (BFS) of a binary tree.
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
    void levelOrder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* cur = q.front(); q.pop();
                cout << cur->val << " ";
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            cout << endl;
        }
    }

    Node* buildTree() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->right = new Node(6);
        return root;
    }

    void solve() {
        Node* root = buildTree();
        cout << "Level Order Traversal:\n";
        levelOrder(root);
    }
};

int main() {
    Solution sol;
    sol.solve();
}
