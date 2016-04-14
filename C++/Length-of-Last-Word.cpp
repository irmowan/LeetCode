class Solution {
 public:
  int lengthOfLastWord(string s) {
    int t = 0;
    int last = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ')
        t++;
      else {
        last = t > 0 ? t : last;
        t = 0;
      }
    }
    last = t > 0 ? t : last;
    return last;
  }
};
