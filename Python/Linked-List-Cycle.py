# Time: O(n)
# Space: O(1)

# Given a linked list, determine if it has a cycle in it.
#
# Follow up:
# Can you solve it without using extra space?

# Definition for singly-linked list.
class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        p1, p2 = head, head
        while p2:
            p1 = p1.next
            p2 = p2.next
            if p2 is None:
                break
            p2 = p2.next
            if p1 == p2:
                return True
        return False

if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = head.next
    print Solution().hasCycle(head)
