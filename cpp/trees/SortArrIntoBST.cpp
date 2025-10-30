/*
Q9. Convert a sorted array into a height-balanced Binary Search Tree (BST).
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
    Node* sortedArrayToBST(vector<int>& arr, int l, int r) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        Node* root = new Node(arr[mid]);
        root->left = sortedArrayToBST(arr, l, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, r);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void solve() {
        vector<int> arr = {-10, -3, 0, 5, 9};
        Node* root = sortedArrayToBST(arr, 0, arr.size() - 1);
        cout << "Inorder Traversal of Balanced BST:\n";
        inorder(root);
        cout << endl;
    }
};

int main() {
    Solution sol;
    sol.solve();
}
