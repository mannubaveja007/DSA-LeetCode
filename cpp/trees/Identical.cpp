/*
Q5. Check if two binary trees are identical.
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
    bool isSame(Node* a, Node* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        return (a->val == b->val) &&
               isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }

    Node* buildTree1() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        return root;
    }

    Node* buildTree2() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        return root;
    }

    void solve() {
        Node* t1 = buildTree1();
        Node* t2 = buildTree2();
        cout << "Trees identical? " << (isSame(t1, t2) ? "Yes" : "No") << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
