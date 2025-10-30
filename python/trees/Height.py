"""
Q2. Find the height (maximum depth) of a binary tree.
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def height(self, root):
        if not root:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))

    def buildTree(self):
        root = Node(1)
        root.left = Node(2)
        root.right = Node(3)
        root.left.left = Node(4)
        root.left.right = Node(5)
        return root

    def solve(self):
        root = self.buildTree()
        print("Height of tree:", self.height(root))

if __name__ == "__main__":
    Solution().solve()
