"""
Q9. Convert a sorted array into a height-balanced Binary Search Tree (BST).
"""

class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

class Solution:
    def sortedArrayToBST(self, arr, l, r):
        if l > r:
            return None
        mid = (l + r) // 2
        root = Node(arr[mid])
        root.left = self.sortedArrayToBST(arr, l, mid - 1)
        root.right = self.sortedArrayToBST(arr, mid + 1, r)
        return root

    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        print(root.val, end=" ")
        self.inorder(root.right)

    def solve(self):
        arr = [-10, -3, 0, 5, 9]
        root = self.sortedArrayToBST(arr, 0, len(arr) - 1)
        print("Inorder Traversal of Balanced BST:")
        self.inorder(root)
        print()

if __name__ == "__main__":
    Solution().solve()
