class Solution {
private:
  int max(int x, int y) {
    if (x < y)
      return y;
    return x;
  }

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n <= 0)
      return 0;
    if (n == 1)
      return nums[0];
    vector<pair<int, int>> dp(n);
    dp[0].first = 0;
    dp[0].second = nums[0];
    dp[1].first = nums[0];
    dp[1].second = nums[1];
    for (int i = 2; i < n; ++i) {
      dp[i].first = max(dp[i - 1].first, dp[i - 1].second);
      dp[i].second = max(dp[i - 2].first, dp[i - 2].second) + nums[i];
    }
    return max(dp[n - 1].first, dp[n - 1].second);
  }
};
