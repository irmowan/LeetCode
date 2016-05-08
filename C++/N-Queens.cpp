class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<int> positions(n);
    vector<vector<string>> result;
    solve(positions, 0, result);
    return result;
  }

 private:
  void solve(vector<int> &positions, int row, vector<vector<string>> &result) {
    int n = positions.size();
    for (int i = 0; i < n; ++i) {
      if (isValid(positions, row, i)) {
        positions[row] = i;
        if (row == n - 1) {
          result.push_back(format(positions));
          continue;
        }
        solve(positions, row + 1, result);
      }
    }
    return;
  }
  bool isValid(vector<int> &positions, int row, int pos) {
    for (int i = 0; i < row; ++i) {
      if (positions[i] == pos || abs(row - i) == abs(positions[i] - pos))
        return false;
    }
    return true;
  }
  vector<string> format(vector<int> &positions) {
    int n = positions.size();
    vector<string> result(n);
    for (int i = 0; i < n; ++i) {
      result[i].resize(n, '.');
      result[i][positions[i]] = 'Q';
    }
    return result;
  }
};
