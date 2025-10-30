/*
Q10. Find the maximum path sum in a binary tree.
*/

class Solution {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    int maxSum = Integer.MIN_VALUE;

    int maxPath(Node root) {
        if (root == null) return 0;
        int l = Math.max(0, maxPath(root.left));
        int r = Math.max(0, maxPath(root.right));
        maxSum = Math.max(maxSum, l + r + root.val);
        return root.val + Math.max(l, r);
    }

    int findMaxPath(Node root) {
        maxPath(root);
        return maxSum;
    }

    Node buildTree() {
        Node root = new Node(-10);
        root.left = new Node(9);
        root.right = new Node(20);
        root.right.left = new Node(15);
        root.right.right = new Node(7);
        return root;
    }

    void solve() {
        Node root = buildTree();
        System.out.println("Maximum Path Sum: " + findMaxPath(root));
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        sol.solve();
    }
}
