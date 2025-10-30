"""
Q5. Check if two binary trees are identical.
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def isSame(self, a, b):
        if not a and not b:
            return True
        if not a or not b:
            return False
        return a.val == b.val and self.isSame(a.left, b.left) and self.isSame(a.right, b.right)

    def buildTree1(self):
        root = Node(1)
        root.left = Node(2)
        root.right = Node(3)
        return root

    def buildTree2(self):
        root = Node(1)
        root.left = Node(2)
        root.right = Node(3)
        return root

    def solve(self):
        t1 = self.buildTree1()
        t2 = self.buildTree2()
        print("Trees identical?", "Yes" if self.isSame(t1, t2) else "No")

if __name__ == "__main__":
    Solution().solve()
