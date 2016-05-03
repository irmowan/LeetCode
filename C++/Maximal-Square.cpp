class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    if (n == 0) return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int max_value = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0) {
          dp[i][j] = (matrix[i][j] == '1');
        } else if (j == 0) {
          dp[i][j] = (matrix[i][j] == '1');
        } else {
          dp[i][j] =
              matrix[i][j] == '1'
                  ? 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]))
                  : 0;
        }
        if (dp[i][j] > max_value) max_value = dp[i][j];
      }
    }
    // for (int i = 0; i < m; ++i) {
    //   for (int j = 0; j < n; ++j) cout << dp[i][j] << " ";
    //   cout << endl;
    // }
    return max_value * max_value;
  }
};
