/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head)
      return head;
    if (k == 0)
      return head;
    ListNode *a, *b, *new_head;
    a = b = head;
    for (int i = 0; i < k; ++i) {
      if (!a->next) {
        a = head;
        // Shorten the k to ensure the loop ends next circle.
        k = k % (i + 1) + (i + 1);
      } else
        a = a->next;
    }
    while (a->next != NULL) {
      a = a->next;
      b = b->next;
    }
    if (!(new_head = b->next))
      return head;
    a->next = head;
    b->next = NULL;
    return new_head;
  }
};
