/*
Q9. Convert a sorted array into a height-balanced Binary Search Tree (BST).
*/

class Solution {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    Node sortedArrayToBST(int[] arr, int l, int r) {
        if (l > r) return null;
        int mid = (l + r) / 2;
        Node root = new Node(arr[mid]);
        root.left = sortedArrayToBST(arr, l, mid - 1);
        root.right = sortedArrayToBST(arr, mid + 1, r);
        return root;
    }

    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    void solve() {
        int[] arr = {-10, -3, 0, 5, 9};
        Node root = sortedArrayToBST(arr, 0, arr.length - 1);
        System.out.println("Inorder Traversal of Balanced BST:");
        inorder(root);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.solve();
    }
}
