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
    vector<int> dp(n);
    // From 0 to n-2
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i)
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    int ans = dp[n - 2];
    // From 1 to n-1
    dp[0] = 0;
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i)
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    ans = max(ans, dp[n - 1]);
    return ans;
  }
};
