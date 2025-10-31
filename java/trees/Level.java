/*
Q4. Perform level order traversal (BFS) of a binary tree.
*/

import java.util.*;

class Level {

    static class Node {
        int val;
        Node left, right;
        Node(int v) { val = v; }
    }

    void levelOrder(Node root) {
        if (root == null) return;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node cur = q.poll();
                System.out.print(cur.val + " ");
                if (cur.left != null) q.add(cur.left);
                if (cur.right != null) q.add(cur.right);
            }
            System.out.println();
        }
    }

    Node buildTree() {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);
        return root;
    }

    void solve() {
        Node root = buildTree();
        System.out.println("Level Order Traversal:");
        levelOrder(root);
    }

    public static void main(String[] args) {
        Level sol = new Level();
        sol.solve();
    }
}
