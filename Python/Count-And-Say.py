# Time: O(n * 2^n)
# Space: O(2^n)
#
# The count-and-say sequence is the sequence of integers beginning as follows:
# 1, 11, 21, 1211, 111221, ...
#
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
# Given an integer n, generate the nth sequence.
#
# Note: The sequence of integers will be represented as a string.


class Solution(object):

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        x = "1"
        for i in range(n - 1):
            x = self.getNext(x)
        return x

    def getNext(self, seq):
        i, ans = 0, ""
        while i < len(seq):
            cnt = 1
            while i < len(seq) - 1 and seq[i] == seq[i + 1]:
                cnt += 1
                i += 1
            ans += str(cnt) + seq[i]
            i += 1
        return ans


if __name__ == '__main__':
    for i in range(10):
        print(Solution().countAndSay(i))
