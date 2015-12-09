# Time: O(n)
# Space: O(1)
#
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
# (you may want to display this pattern in a fixed font for better legibility)
#
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:
#
# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
#

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        step, zigzag = 2 * numRows - 2, ""
        if s is None or len(s) < 1 or numRows <= 0:
                return ""
        if numRows == 1:
            return s
        for i in xrange(numRows):
            for j in xrange(i, len(s), step):
                # j is the order of the s
                zigzag += s[j]
                # Here, j + step - 2 * i defines the order of the num
                if i > 0 and i < numRows - 1 and j + step - 2 * i < len(s):
                    zigzag += s[j + step - 2 * i]
        return zigzag
