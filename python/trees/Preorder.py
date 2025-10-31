"""
Q1. Create a binary tree and perform inorder traversal.
"""
class Node:
    def __init__(self, val):
        self.val = val
        self.left = self.right = None

def inorder(root):
    if not root: return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.right = Node(4)
inorder(root)
