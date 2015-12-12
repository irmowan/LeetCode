# Time: O(n)
# Space: O(1)
#
# Determine whether an integer is a palindrome. Do this without extra space.
#
# click to show spoilers.
#
# Some hints:
# Could negative integers be palindromes? (ie, -1)
#
# If you are thinking of converting the integer to string, note the restriction of using extra space.
#
# You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
#
# There is a more generic way of solving this problem.
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        temp = x
        y = 0
        while (temp > 0):
            y = y * 10 + temp % 10
            temp = temp / 10
        if x == y :
            return True
        else:
            return False

if __name__ == "__main__":
    print(Solution().isPalindrome(-13))
    print(Solution().isPalindrome(919))
    print(Solution().isPalindrome(120))
