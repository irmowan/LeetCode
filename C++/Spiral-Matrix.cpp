class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.empty())
      return {};
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0, r = n - 1, u = 0, d = m - 1;
    while (true) {
      for (int col = l; col <= r; ++col)
        result.push_back(matrix[u][col]);
      if (++u > d)
        break;
      for (int row = u; row <= d; ++row)
        result.push_back(matrix[row][r]);
      if (--r < l)
        break;
      for (int col = r; col >= l; --col)
        result.push_back(matrix[d][col]);
      if (--d < u)
        break;
      for (int row = d; row >= u; --row)
        result.push_back(matrix[row][l]);
      if (++l > r)
        break;
    }
    return result;
  }
};