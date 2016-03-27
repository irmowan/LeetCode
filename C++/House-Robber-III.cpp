/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  int robCurr(TreeNode *root, int &l, int &r) {
    if (!root)
      return 0;
    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = robCurr(root->left, ll, lr);
    r = robCurr(root->right, rl, rr);
    return max(root->val + ll + lr + rl + rr, l + r);
  }

public:
  int rob(TreeNode *root) {
    int l, r;
    return robCurr(root, l, r);
  }
};
