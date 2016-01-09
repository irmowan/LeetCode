# Time: O(logn)
# Space: O(logn)
#
# Given a binary tree, find its minimum depth.
#
# The minimum depth is the number of nodes along the shortest path from
# the root node down to the nearest leaf node.

# Definition for a binary tree node.


class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        if (left == 0 and right == 0):
            return 1
        if (left == 0):
            return right + 1
        if (right == 0):
            return left + 1
        return min(left, right) + 1

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    print Solution().minDepth(root)
