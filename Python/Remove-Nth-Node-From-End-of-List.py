# Time: O(n)
# Space: O(1)
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
        dummy = ListNode(-1)
        dummy.next = head
        slow, fast = dummy, dummy
        for i in range(n):
            fast = fast.next
        while fast.next:
            slow, fast = slow.next, fast.next
        slow.next = slow.next.next
        return dummy.next

if __name__ == '__main__':
    a, a.next, a.next.next, a.next.next.next, a.next.next.next.next = \
    ListNode(1), ListNode(2), ListNode(3), ListNode(4), ListNode(5)
    ans = Solution().removeNthFromEnd(a, 2)
    print(ans)
