# Time: O(n)
# Space: O(n)

# Given a binary tree, find the maximum path sum.
#
# For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
#
# For example:
# Given the below binary tree,
#
#        1
#       / \
#      2   3
# Return 6.

# Definition for a binary tree node.


class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.maxPathSumRecu(root)[0]

    def maxPathSumRecu(self, root):
        if root is None:
            return float("-inf"), float("-inf")
        left_inner, left_link = self.maxPathSumRecu(root.left)
        right_inner, right_link = self.maxPathSumRecu(root.right)

        link = max(left_link, right_link, 0) + root.val
        inner = max(left_link + root.val + right_link,
                    link, left_inner, right_inner)
        return inner, link

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    result = Solution().maxPathSum(root)
    print result
