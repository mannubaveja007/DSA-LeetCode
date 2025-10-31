/*
Q6. Find the diameter (longest path between any two nodes) of a binary tree.
*/

class Diameter {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    int diameter = 0;

    int height(Node root) {
        if (root == null) return 0;
        int l = height(root.left);
        int r = height(root.right);
        diameter = Math.max(diameter, l + r);
        return 1 + Math.max(l, r);
    }

    int findDiameter(Node root) {
        height(root);
        return diameter;
    }

    Node buildTree() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        return root;
    }

    void solve() {
        Node root = buildTree();
        System.out.println("Diameter of tree: " + findDiameter(root));
    }

    public static void main(String[] args) {
        Diameter sol = new Diameter();
        sol.solve();
    }
}
