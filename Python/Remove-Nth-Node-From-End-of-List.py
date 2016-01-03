# Time: O()
# Space: O()
# Given a linked list, remove the nth node from the end of list and return its head.
#
# For example,
#
#    Given linked list: 1->2->3->4->5, and n = 2.
#
#    After removing the second node from the end, the linked list becomes 1->2->3->5.
# Note:
# Given n will always be valid.
# Try to do this in one pass.

# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        sum1 = 0
        x = head
        while x:
            x = x.next
            sum1 += 1
        x = head
        if sum1 == n:
            return x.next
        sum2 = 0
        while x:
            sum2 += 1
            if sum2 == sum1 - n:
                x.next = x.next.next
                return head
            x = x.next

if __name__ == '__main__':
    a, a.next, a.next.next, a.next.next.next, a.next.next.next.next = \
    ListNode(1),ListNode(2), ListNode(3), ListNode(4), ListNode(5)
    ans = Solution().removeNthFromEnd(a, 2)
    print(ans)
