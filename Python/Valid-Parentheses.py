# Time: O(n)
# Space: O(n)

# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#
# The brackets must close in the correct order, "()" and "()[]{}" are all
# valid but "(]" and "([)]" are not.


class Solution(object):

    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        match = {')': '(', ']': '[', '}': '{'}
        stack = []
        for c in s:
            if c in match:
                if not(stack and stack.pop() == match[c]):
                    return False
            else:
                stack.append(c)
        if stack:
            return False
        return True

if __name__ == '__main__':
    print Solution().isValid("()[]{}[]")
    print Solution().isValid("()[{]}[]")
