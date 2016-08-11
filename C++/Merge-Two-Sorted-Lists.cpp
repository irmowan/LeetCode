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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode{0};
    ListNode *l = head;
    while (l1 != NULL && l2 != NULL) {
      if (l1->val > l2->val) {
        l->next = new ListNode(l2->val);
        l2 = l2->next;
      } else {
        l->next = new ListNode(l1->val);
        l1 = l1->next;
      }
      l = l->next;
    }
    while (l1 != NULL) {
      l->next = new ListNode(l1->val);
      l1 = l1->next;
      l = l->next;
    }
    while (l2 != NULL) {
      l->next = new ListNode(l2->val);
      l2 = l2->next;
      l = l->next;
    }
    return head->next;
  }
};