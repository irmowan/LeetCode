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
        Roman = {"I":1, "V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        s = ""
        n1 = num / 1000;
        n2 = (num - n1 * 1000) / 100
        n3 = (num / 10) % 10
        n4 = num % 10
        s += n1 * "M"
        if n2 == 4:
            s += "CD"
        elif n2 == 9:
            s += "CM"
        else:
            if n2 >= 5:
                s += "D"
            s += (n2 % 5) * "C"
        # tens digit
        if n3 == 4:
            s += "XL"
        elif n3 == 9:
            s += "XC"
        else:
            if n3 >= 5:
                s += "L"
            s += (n3 % 5) * "X"
        # last digit
        if n4 == 4:
            s += "IV"
        elif n4 == 9:
            s += "IX"
        else:
            if n4 >= 5:
                s += "V"
            s += (n4 % 5) * "I"
        return s



if __name__ == '__main__':
    print(Solution().intToRoman(49))
    print(Solution().intToRoman(1995))
    print(Solution().intToRoman(1453))
