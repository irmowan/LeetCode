class Solution {
public:
  int minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();
    if (l1 == 0)
      return l2;
    if (l2 == 0)
      return l1;
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i) {
      for (int j = 0; j <= l2; ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = 0;
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] + 1;
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + 1;
        } else {
          dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                         dp[i - 1][j - 1] + 1);
          if (word1[i - 1] == word2[j - 1])
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
      }
    }
    return dp[l1][l2];
  }
};
