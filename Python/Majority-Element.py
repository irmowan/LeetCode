# Time: O(n)
# Space: O(1)
# Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.
#
# You may assume that the array is non-empty and the majority element always exist in the array.
#


class Solution(object):

    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Moore's voting algorithm
        ans, s = None, 0
        for x in nums:
            if ans == x:
                s += 1
            elif ans == None:
                ans, s = x, 1
            else:
                s -= 1
                if s == 0:
                    ans = None
        return ans

if __name__ == '__main__':
    nums = [1, 2, 3, 4, 4, 3, 4, 5, 4, 4, 4, 1]
    print Solution().majorityElement(nums)
