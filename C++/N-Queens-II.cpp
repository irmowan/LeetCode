class Solution {
 public:
  int totalNQueens(int n) {
    vector<int> positions(n);
    solve(positions, 0);
    return this->result;
  }

 private:
  int result = 0;
  void solve(vector<int> &positions, int row) {
    int n = positions.size();
    for (int i = 0; i < n; ++i) {
      if (isValid(positions, row, i)) {
        positions[row] = i;
        if (row == n - 1) {
          this->result += 1;
          continue;
        }
        solve(positions, row + 1);
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
};
