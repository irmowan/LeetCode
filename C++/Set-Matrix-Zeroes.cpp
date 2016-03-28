class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    long long x, y;
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j)
        if (matrix[i][j] == 0) {
          if (!((x >> i) & 1))
            x += 1 << i;
          if (!((y >> j) & 1))
            y += 1 << j;
        }
    for (int i = 0; i < matrix.size(); ++i)
      for (int j = 0; j < matrix[0].size(); ++j) {
        if ((x >> i) & 1)
          matrix[i][j] = 0;
        if ((y >> j) & 1)
          matrix[i][j] = 0;
      }
    return;
  }
};
