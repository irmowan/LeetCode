class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
      return 0;
    int pos[128];
    memset(pos, -1, sizeof(pos));
    int curlen, maxlen, max_index, last_start;
    max_index = last_start = 0;
    maxlen = curlen = 1;
    pos[s[0]] = 0;
    for (int i = 1; i < s.size(); ++i) {
      int c = s[i];
      if (pos[c] == -1) {
        ++curlen;
        pos[c] = i;
      } else {
        if (last_start <= pos[c]) {
          curlen = i - pos[c];
          last_start = pos[c] + 1;
          pos[c] = i;
        } else {
          ++curlen;
          pos[c] = i;
        }
      }
      if (curlen > maxlen) {
        maxlen = curlen;
        max_index = i + 1 - maxlen;
      }
    }
    return maxlen;
  }
};
