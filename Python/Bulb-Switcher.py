# Time: O(1)
# Space: O(1)
#
# There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.
#
# Example:
#
# Given n = 3.
#
# At first, the three bulbs are [off, off, off].
# After first round, the three bulbs are [on, on, on].
# After second round, the three bulbs are [on, off, on].
# After third round, the three bulbs are [on, off, off].
#
# So you should return 1, because there is only one bulb is on.

# Solution:
# for blub i, it checks all the numbers from 1 to i whether it could divide i,
# so the times it switches is the factors it has. And if the blub keep the state
# of on, the number of its factors is odd, which means that i is a square number.
# So the question changes to, how many square numbers from 1 to n?
import math

class Solution(object):
    def bulbSwitch(self, n):
        """
        :type n: int
        :rtype: int
        """
        return int(math.sqrt(n))

if __name__ == '__main__':
    print(Solution().bulbSwitch(99))
