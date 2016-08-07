class Solution {
public:
  string shortestPalindrome(string s) {
    string t(s);
    reverse(t.begin(), t.end());
    for (int i = 0; i < t.size(); ++i) {
      if (t.substr(i) == s.substr(0, s.size() - i)) {
        return t.substr(0, i) + s;
      }
    }
    return t + s;
  }
};