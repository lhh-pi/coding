class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


if __name__ == "__main__":

    tree1 = TreeNode(1)
    tree2 = TreeNode(2)
    tree0 = TreeNode(0, tree1, tree2)
    print(tree0.left.val)