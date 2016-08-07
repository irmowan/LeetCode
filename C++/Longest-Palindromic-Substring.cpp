class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2)
      return s;
    int max_left = 0;
    int max_len = 1;
    int i = 0;
    while (i < s.size() && len - i > max_len / 2) {
      int left, right;
      left = right = i;
      while (right < len - 1 && s[right] == s[right + 1]) {
        ++right;
      }
      i = right + 1;
      while (left > 0 && right < len - 1 && s[left - 1] == s[right + 1]) {
        --left;
        ++right;
      }
      if (right - left + 1 > max_len) {
        max_len = right - left + 1;
        max_left = left;
      }
    }
    return s.substr(max_left, max_len);
  }
};