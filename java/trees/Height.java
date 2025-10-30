 /*
Q2. Find the height (maximum depth) of a binary tree.
*/

class Height {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    int height(Node root) {
        if (root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
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
        System.out.println("Height of tree: " + height(root));
    }

    public static void main(String[] args) {
        Height sol = new Height();
        sol.solve();
    }
}
