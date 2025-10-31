"""
Q7. Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def LCA(self, root, p, q):
        if not root or root == p or root == q:
            return root
        left = self.LCA(root.left, p, q)
        right = self.LCA(root.right, p, q)
        if left and right:
            return root
        return left if left else right

    def buildTree(self):
        root = Node(3)
        root.left = Node(5)
        root.right = Node(1)
        root.left.left = Node(6)
        root.left.right = Node(2)
        root.right.left = Node(0)
        root.right.right = Node(8)
        return root

    def solve(self):
        root = self.buildTree()
        p = root.left          # 5
        q = root.left.right    # 2
        lca = self.LCA(root, p, q)
        print(f"LCA of {p.val} and {q.val} is: {lca.val}")

if __name__ == "__main__":
    Solution().solve()
