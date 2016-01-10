# Reverse a singly linked list.
#
# click to show more hints.
#
# Hint:
# A linked list can be reversed either iteratively or recursively. Could
# you implement both?

# Definition for singly-linked list.


class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    """Recursive Version"""

    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        begin, end = self.reverse(head)
        return begin

    def reverse(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None, None
        if head.next is None:
            return head, head
        h, t = self.reverse(head.next)
        t.next = head
        head.next = None
        return h, head


class Solution2(object):
    """Iterative Version"""

    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        l, ans, current = [], None, head
        while (current):
            l.append(current.val)
            current = current.next
        for val in l:
            x = ListNode(val)
            x.next = ans
            ans = x
        return ans

if __name__ == '__main__':
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(3)
    l1.next.next.next = ListNode(4)
    rl1 = Solution().reverseList(l1)
    print rl1.val, rl1.next.val, rl1.next.next.val, rl1.next.next.next.val
    l2 = ListNode(1)
    l2.next = ListNode(2)
    l2.next.next = ListNode(3)
    l2.next.next.next = ListNode(4)
    rl2 = Solution2().reverseList(l2)
    print rl2.val, rl2.next.val, rl2.next.next.val, rl2.next.next.next.val
