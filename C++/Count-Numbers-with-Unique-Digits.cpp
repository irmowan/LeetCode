class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    vector<int> ans;
    ans.push_back(1);
    int x = 1;
    for (int i = 0; i < n; ++i) {
      if (x == 1)
        x *= 9;
      else
        x *= (10 - i);
      ans.push_back(x);
    }
    return accumulate(ans.begin(), ans.end(), 0);
  }
};