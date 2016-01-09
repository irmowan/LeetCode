# Time: O(n)
# Space: O(n)
#
# Given a binary tree, return the postorder traversal of its nodes' values.
#
# For example:
# Given binary tree {1,#,2,3},
#    1
#     \
#      2
#     /
#    3
# return [3,2,1].

# Note: Recursive solution is trivial, could you do it iteratively?

# Definition for a binary tree node.


class TreeNode(object):

    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans, stack, current = [], [], root
        while stack or current:
            if current:
                if not hasattr(current, 'visited'):
                    current.visited = 0
                    stack.append(current)
                    current = current.left
                elif current.visited == 0:
                    current.visited = 1
                    stack.append(current)
                    current = current.right
                elif current.visited == 1:
                    current.visited = 2
                    ans.append(current.val)
                    if len(stack) == 0:
                        return ans
                    current = stack.pop()
            else:
                current = stack.pop()
        return ans


class Solution2(object):

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        return self.postorderTraversal(root.left) + \
            self.postorderTraversal(root.right) + [root.val]

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    print Solution().postorderTraversal(root)
