/*
Q1. Create a binary tree and perform inorder traversal.
*/

class Height{

    // Node class (inner class)
    static class Node {
        int val;
        Node left, right;

        Node(int v) {
            val = v;
        }
    }

    // Inorder traversal method
    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    // Method to build and return a binary tree
    Node buildTree() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(4);
        return root;
    }

    // Method to execute logic
    void solve() {
        Node root = buildTree();
        System.out.println("Inorder Traversal:");
        inorder(root);
    }

    // Main method
    public static void main(String[] args) {
        Height sol = new Height();
        sol.solve();
    }
}

