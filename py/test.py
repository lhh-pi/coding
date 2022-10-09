from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def inorder(self, arr):
        arr.append(self.val)
        if self.left:
            self.left.inorder(arr)
        if self.right:
            self.right.inorder(arr)

    def print(self):
        out = []
        self.inorder(out)
        print(out)

    def print_val(self):
        print(self.val)

    def print_item(self):
        print(self.val)
        if self.left:
            self.left.print_val()
        else:
            print('None')
        if self.right:
            self.right.print_val()
        else:
            print('None')


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        q1, q2 = [root], []
        while q1:
            for node in q1:
                node.print_item()
                if node.right:
                    q2.append(node.right)
                if node.left:
                    q2.append(node.left)
                node.right, node.left = node.left, node.right
                node.print_item()
            q1, q2 = q2, []
        return root


if __name__ == "__main__":
    s = Solution()
    t6 = TreeNode(9)
    t5 = TreeNode(6)
    t4 = TreeNode(3)
    t3 = TreeNode(1)
    t2 = TreeNode(7, t5, t6)
    t1 = TreeNode(2, t3, t4)
    root = TreeNode(4, t1, t2)
    root.print()
    root = s.invertTree(root)
    root.print()
