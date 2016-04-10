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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size();
    // ListNode head(0); is wrong!
    // Using new to ensure 'head' is a heap variable, not a stack variable.
    ListNode* head = new ListNode(0);
    ListNode* now = head;
    vector<ListNode*> p(len, NULL);
    for (int i = 0; i < len; ++i) {
      p[i] = lists[i];
    }
    while (true) {
      int min_index, min_value;
      bool end = true;
      min_index = 0;
      min_value = INT_MAX;
      for (int i = 0; i < len; ++i) {
        if (!p[i]) continue;
        end = false;
        if (p[i]->val < min_value) {
          min_index = i;
          min_value = p[i]->val;
        }
      }
      if (end) break;
      ListNode* new_node = new ListNode(min_value);
      now->next = new_node;
      now = now->next;
      p[min_index] = (p[min_index])->next;
    }
    return head->next;
  }
};
