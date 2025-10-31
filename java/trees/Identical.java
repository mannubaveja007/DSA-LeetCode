/*
Q5. Check if two binary trees are identical.
*/

class Identical {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    boolean isSame(Node a, Node b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        return (a.val == b.val)
            && isSame(a.left, b.left)
            && isSame(a.right, b.right);
    }

    Node buildTree1() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        return root;
    }

    Node buildTree2() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        return root;
    }

    void solve() {
        Node t1 = buildTree1();
        Node t2 = buildTree2();
        System.out.println("Trees identical? " + isSame(t1, t2));
    }

    public static void main(String[] args) {
        Identical sol = new Identical();
        sol.solve();
    }
}
 