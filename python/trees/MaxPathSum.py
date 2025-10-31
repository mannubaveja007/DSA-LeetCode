"""
Q10. Find the maximum path sum in a binary tree.
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def __init__(self):
        self.maxSum = float('-inf')

    def maxPath(self, root):
        if not root:
            return 0
        l = max(0, self.maxPath(root.left))
        r = max(0, self.maxPath(root.right))
        self.maxSum = max(self.maxSum, l + r + root.val)
        return root.val + max(l, r)

    def findMaxPath(self, root):
        self.maxPath(root)
        return self.maxSum

    def buildTree(self):
        root = Node(-10)
        root.left = Node(9)
        root.right = Node(20)
        root.right.left = Node(15)
        root.right.right = Node(7)
        return root

    def solve(self):
        root = self.buildTree()
        print("Maximum Path Sum:", self.findMaxPath(root))

if __name__ == "__main__":
    Solution().solve()
