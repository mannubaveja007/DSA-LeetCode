"""
Q6. Find the diameter (longest path between any two nodes) of a binary tree.
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def __init__(self):
        self.diameter = 0

    def height(self, root):
        if not root:
            return 0
        l = self.height(root.left)
        r = self.height(root.right)
        self.diameter = max(self.diameter, l + r)
        return 1 + max(l, r)

    def findDiameter(self, root):
        self.height(root)
        return self.diameter

    def buildTree(self):
        root = Node(1)
        root.left = Node(2)
        root.right = Node(3)
        root.left.left = Node(4)
        root.left.right = Node(5)
        return root

    def solve(self):
        root = self.buildTree()
        print("Diameter of tree:", self.findDiameter(root))

if __name__ == "__main__":
    Solution().solve()
