# Time: O(1)
# Space: O(1)
# Given a string containing only digits, restore it by returning all possible valid IP address combinations.
#
# For example:
# Given "25525511135",
#
# return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


class Solution(object):

    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ans = []
        divides = [[a, b, c, d] for a in range(1, 4) for b in range(
            1, 4) for c in range(1, 4) for d in range(1, 4) if a + b + c + d == len(s)]
        for divide in divides:
            a, b, c, d = divide
            sa = s[0:a]
            sb = s[a:a + b]
            sc = s[a + b:a + b + c]
            sd = s[a + b + c:]
            if int(sa) < 256 and int(sb) < 256 and int(sc) < 256 and int(sd) < 256 and \
            str(int(sa)) == sa and str(int(sb)) == sb and str(int(sc)) == sc and str(int(sd)) == sd:
                ans.append('.'.join([sa, sb, sc, sd]))
        return ans

if __name__ == '__main__':
    print Solution().restoreIpAddresses("0000")
    print Solution().restoreIpAddresses("25525511135")
    print Solution().restoreIpAddresses("010010")
