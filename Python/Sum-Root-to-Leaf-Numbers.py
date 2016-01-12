# Time: O(n)
# Space: O(n)

# Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
#
# An example is the root-to-leaf path 1->2->3 which represents the number 123.
#
# Find the total sum of all root-to-leaf numbers.
#
# For example,
#
#     1
#    / \
#   2   3
# The root-to-leaf path 1->2 represents the number 12.
# The root-to-leaf path 1->3 represents the number 13.
#
# Return the sum = 12 + 13 = 25.

# Definition for a binary tree node.


class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        return self.sumNumbersRecu(root, 0)

    def sumNumbersRecu(self, root, val):
        new_val = val * 10 + root.val
        if not root.left and not root.right:
            return new_val
        if root.left and not root.right:
            return self.sumNumbersRecu(root.left, new_val)
        if not root.left and root.right:
            return self.sumNumbersRecu(root.right, new_val)
        left = self.sumNumbersRecu(root.left, new_val)
        right = self.sumNumbersRecu(root.right, new_val)
        return left + right

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    print Solution().sumNumbers(root)
