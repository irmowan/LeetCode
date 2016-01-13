# Time: O(n)
# Space: O(1)

# Given an array of integers, every element appears three times except for one. Find that single one.
#
# Note:
# Your algorithm should have a linear runtime complexity. Could you
# implement it without using extra memory?


class Solution(object):

    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        one, two = 0, 0
        for x in nums:
            one, two, three = one ^ x, two | (one & x), two & x
            one, two = one & ~three, two & ~three
        return one

if __name__ == '__main__':
    nums = [1, 3, 6, 1, 8, 4, 7, 7, 4, 8, 1, 7, 6, 6, 8, 4]
    print Solution().singleNumber(nums)
