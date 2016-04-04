class Solution {
 private:
  int dfs(int& m, int& n, int i, int j, vector<vector<int>>& matrix,
          vector<vector<int>>& ans) {
    if (i < 0 || j < 0 || i >= m || j >= n) return 0;
    if (ans[i][j] != 0) return ans[i][j];
    int l, r, u, d;
    l = r = u = d = 1;
    ans[i][j] = 1;
    if (i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j])
      u = 1 + dfs(m, n, i - 1, j, matrix, ans);
    if (i + 1 < m && matrix[i][j] < matrix[i + 1][j])
      d = 1 + dfs(m, n, i + 1, j, matrix, ans);
    if (j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1])
      l = 1 + dfs(m, n, i, j - 1, matrix, ans);
    if (j + 1 < n && matrix[i][j] < matrix[i][j + 1])
      r = 1 + dfs(m, n, i, j + 1, matrix, ans);
    ans[i][j] = max(max(u, d), max(l, r));
    return ans[i][j];
  }

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m, n, max_value;
    m = matrix.size();
    if (m == 0) return 0;
    n = matrix[0].size();
    if (n == 0) return 0;
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) cout << ans[i][j] << " ";
      cout << endl;
    }
    max_value = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (ans[i][j] == 0) {
          int temp = dfs(m, n, i, j, matrix, ans);
          if (temp > max_value) max_value = temp;
        }
      }
    }
    return max_value;
  }
};
