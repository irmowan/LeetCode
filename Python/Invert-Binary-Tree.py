# Time: O(logn)
# Space: O(n)

# Invert a binary tree.

# Definition for a binary tree node.

class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return
        new_root = TreeNode(root.val)
        new_root.left, new_root.right = self.invertTree(
            root.right), self.invertTree(root.left)
        return new_root

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    invert_root = Solution().invertTree(root)
    print(invert_root.left.val, invert_root.right.val,
          invert_root.right.right.val)
