"""
Q4. Perform level order traversal (BFS) of a binary tree.
"""

from collections import deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def levelOrder(self, root):
        if not root:
            return
        q = deque([root])
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                print(node.val, end=" ")
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            print()

    def buildTree(self):
        root = Node(1)
        root.left = Node(2)
        root.right = Node(3)
        root.left.left = Node(4)
        root.left.right = Node(5)
        root.right.right = Node(6)
        return root

    def solve(self):
        root = self.buildTree()
        print("Level Order Traversal:")
        self.levelOrder(root)

if __name__ == "__main__":
    Solution().solve()
