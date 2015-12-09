# Time: O(n)
# Space: O(n)
#
# Given an array of integers, find two numbers such that
# they add up to a specific target number.

# The function twoSum should return indices of the two numbers
# such that they add up to the target, where index1 must be less than index2.
# Please note that your returned answers (both index1 and index2) are not zero-based.

# You may assume that each input would have exactly one solution.

# Input: numbers={2, 7, 11, 15}, target=9
# Output: index1=1, index2=2

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def find(nums, x, y):
            if x != y:
                m, n = nums.index(x) + 1, nums.index(y) + 1
                if m > n:
                    m, n = n, m
                return m, n
            m = nums.index(x)
            del nums[m]
            return m + 1, nums.index(y) + 2
        a = sorted(nums)
        p = 0
        q = len(a) - 1
        while (a[p] <= a[q]):
            while a[p] + a[q] > target:
                q = q - 1
            if a[p] + a[q] == target:
                return find(nums, a[p], a[q])
            p = p + 1
        return
