class Solution {
 public:
  string convertToTitle(int n) {
    string s = "";
    int t;
    if (n <= 0) return s;
    while (n > 0) {
      t = (n - 1) % 26;
      s = (char)('A' + t) + s;
      n = (n - 1) / 26;
    }
    return s;
  }
};
