class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int l = triangle.size();
    if (l == 0) return 0;
    vector<int> old_dp(1, 0), new_dp(1, 0);
    new_dp[0] = triangle[0][0];
    for (int i = 1; i < l; ++i) {
      old_dp = new_dp;
      new_dp.resize(i + 1);
      for (int j = 0; j <= i; ++j) {
        if (j == 0) {
          new_dp[j] = old_dp[j] + triangle[i][j];
        } else if (j == i) {
          new_dp[j] = old_dp[j - 1] + triangle[i][j];
        } else {
          new_dp[j] = min(old_dp[j - 1], old_dp[j]) + triangle[i][j];
        }
      }
    }
    int min_value = INT_MAX;
    for (int i = 0; i < l; ++i)
      if (new_dp[i] < min_value) min_value = new_dp[i];
    return min_value;
  }
};
