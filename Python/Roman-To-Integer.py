# Time: O(n)
# Space: O(1)
# Given a roman numeral, convert it to an integer.
#
# Input is guaranteed to be within the range from 1 to 3999.

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        Roman = {"I":1, "V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        dem = 0
        for i in xrange(len(s)):
            if (i == 0 or Roman[s[i]] <= Roman[s[i-1]]):
                dem = dem + Roman[s[i]]
            else:
                dem = dem + Roman[s[i]] - 2 * Roman[s[i-1]]
        return dem

if __name__ == '__main__':
    print(Solution().romanToInt('DCIV'))
