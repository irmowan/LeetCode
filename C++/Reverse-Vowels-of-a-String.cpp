class Solution {
 public:
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !test(s[i])) ++i;
      while (i < j && !test(s[j])) --j;
      swap(s[i], s[j]);
      ++i, --j;
    }
    return s;
  }
  bool test(char t) {
    if (t == 'a' || t == 'e' || t == 'o' || t == 'u' || t == 'i') return true;
    if (t == 'A' || t == 'E' || t == 'O' || t == 'U' || t == 'I') return true;
    return false;
  }
};
