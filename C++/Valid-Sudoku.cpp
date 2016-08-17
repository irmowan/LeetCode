class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int size = board.size();
    vector<int> row_valid(size, 0);
    vector<int> col_valid(size, 0);
    vector<int> box_valid(size, 0);
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        char c = board[i][j];
        if (c == '.')
          continue;
        int mask = 1 << int(c - '0');
        int k = 3 * (i / 3) + (j / 3);
        if (row_valid[i] & mask || col_valid[j] & mask || box_valid[k] & mask)
          return false;
        row_valid[i] |= mask;
        col_valid[j] |= mask;
        box_valid[k] |= mask;
      }
    }
    return true;
  }
};