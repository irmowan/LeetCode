class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    vector<int> result;
    if (nums.empty())
      return result;
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    vector<int> son(nums.size(), 0);
    dp[0] = 1;
    int max_dp = 1, max_index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          son[i] = j;
        }
      }
      if (dp[i] > max_dp) {
        max_dp = dp[i];
        max_index = i;
      }
    }

    int k = max_index;
    for (int i = 0; i < max_dp; ++i) {
      result.push_back(nums[k]);
      k = son[k];
    }
    return result;
  }
};