# Time: O(n)
# Space: O(1)

# Given an array of integers, every element appears twice except for one. Find that single one.
#
# Note:
# Your algorithm should have a linear runtime complexity. Could you
# implement it without using extra memory?

import operator

class Solution(object):

    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(operator.xor, nums)

if __name__ == '__main__':
    nums = [1, 3, 6, 3, 1, 8, 4, 7, 4, 7, 8]
    print Solution().singleNumber(nums)
