# Time:
# Space:
#
# Given an integer, convert it to a roman numeral.
#
# Input is guaranteed to be within the range from 1 to 3999

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        Roman = {1:"I", 4:"IV", 5:"V", 9:"IX", 10:"X", 40:"XL", 50:"L", 90:"XC", 100:"C", 400:"CD", 500:"D", 900:"CM", 1000:"M"}
        keyset = sorted(Roman.keys())
        s = ""
        for key in reversed(keyset):
            while num/key > 0:
                num -= key
                s += Roman[key]
        return s



if __name__ == '__main__':
    print(Solution().intToRoman(49))
    print(Solution().intToRoman(1995))
    print(Solution().intToRoman(1453))
