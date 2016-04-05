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
  ListNode* swapPairs(ListNode* head) {
    if (!head) return head;
    ListNode raw_head(0);
    raw_head.next = head;
    head = &raw_head;
    ListNode *p1, *p2;
    p1 = head;
    p2 = head->next;
    while (p2 && p2->next) {
      cout << p1->val << p2->val << endl;
      ListNode* temp = p2->next->next;
      p1->next = p2->next;
      p2->next = temp;
      p1->next->next = p2;
      p1 = p2;
      p2 = p2->next;
    }
    head = head->next;
    return head;
  }
};
