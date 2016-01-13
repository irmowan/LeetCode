# Time: O(n)
# Space: O(n)

# Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
#
# For example:
# Given the below binary tree and sum = 22,
#               5
#              / \
#             4   8
#            /   / \
#           11  13  4
#          /  \    / \
#         7    2  5   1
# return
# [
#    [5,4,11,2],
#    [5,8,4,5]
# ]


# Definition for a binary tree node.
class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        return self.pathSumRecu(root, sum, [], [])

    def pathSumRecu(self, root, sum, result, curr):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool, List[List[int]]
        """
        if root is None:
            return result
        if root.left is None and root.right is None:
            if sum == root.val:
                result.append(curr + [root.val])
            return result
        self.pathSumRecu(root.left, sum - root.val, result, curr + [root.val])
        self.pathSumRecu(root.right, sum - root.val, result, curr + [root.val])
        return result

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    print Solution().pathSum(root, 8)
