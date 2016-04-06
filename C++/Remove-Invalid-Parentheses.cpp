class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    remove(s, ans, 0, 0, '(', ')');
    return ans;
  }
  void remove(string s, vector<string> &ans, int last_i, int last_j, char left,
              char right) {
    for (int stack = 0, i = last_i; i < s.size(); ++i) {
      if (s[i] == left) ++stack;
      if (s[i] == right) --stack;
      if (stack >= 0) continue;
      for (int j = last_j; j <= i; ++j)
        if (s[j] == right && (j == last_j || s[j - 1] != right)) {
          remove(s.substr(0, j) + s.substr(j + 1, s.size()), ans, i, j, left,
                 right);
        }
      return;
    }
    string reversed;
    reversed.assign(s.rbegin(), s.rend());
    if (left == '(')
      remove(reversed, ans, 0, 0, ')', '(');
    else
      ans.push_back(reversed);
  }
};
