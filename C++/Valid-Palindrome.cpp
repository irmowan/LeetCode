class Solution {
 public:
  bool isPalindrome(string s) {
    int l = s.size();
    if (l == 0) return true;
    string t = "";
    for (int i = 0; i < l; ++i)
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        t += s[i];
      else if (s[i] >= 'A' && s[i] <= 'Z')
        t += s[i] + ('a' - 'A');
    for (int i = 0; i < t.size() / 2; ++i)
      if (t[i] != t[t.size() - 1 - i]) return false;
    return true;
  }
};
