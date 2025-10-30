/*
Q7. Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
*/

class LCASol {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    Node LCA(Node root, Node p, Node q) {
        if (root == null || root == p || root == q) return root;
        Node left = LCA(root.left, p, q);
        Node right = LCA(root.right, p, q);
        if (left != null && right != null) return root;
        return (left != null) ? left : right;
    }

    Node buildTree() {
        Node root = new Node(3);
        root.left = new Node(5);
        root.right = new Node(1);
        root.left.left = new Node(6);
        root.left.right = new Node(2);
        root.right.left = new Node(0);
        root.right.right = new Node(8);
        return root;
    }

    void solve() {
        Node root = buildTree();
        Node p = root.left;  // 5
        Node q = root.left.right; // 2
        Node lca = LCA(root, p, q);
        System.out.println("LCA of " + p.val + " and " + q.val + " is: " + lca.val);
    }

    public static void main(String[] args) {
        LCASol sol = new LCASol();
        sol.solve();
    }
}
