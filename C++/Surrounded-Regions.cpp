class Solution {

public:
  void solve(vector<vector<char>> &board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();
    if (n == 0)
      return;
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
      if (board[i][0] == 'O')
        q.push(make_pair(i, 0));
      if (board[i][n - 1] == 'O')
        q.push(make_pair(i, n - 1));
    }
    for (int j = 1; j < n - 1; ++j) {
      if (board[0][j] == 'O')
        q.push(make_pair(0, j));
      if (board[m - 1][j] == 'O')
        q.push(make_pair(m - 1, j));
    }
    while (q.size() > 0) {
      pair<int, int> temp = q.front();
      q.pop();
      board[temp.first][temp.second] = 'o';
      if (temp.first - 1 >= 0 && board[temp.first - 1][temp.second] == 'O') {
        q.push(make_pair(temp.first - 1, temp.second));
      }
      if (temp.first + 1 < m && board[temp.first + 1][temp.second] == 'O') {
        q.push(make_pair(temp.first + 1, temp.second));
      }
      if (temp.second - 1 >= 0 && board[temp.first][temp.second - 1] == 'O') {
        q.push(make_pair(temp.first, temp.second - 1));
      }
      if (temp.second + 1 < n && board[temp.first][temp.second + 1] == 'O') {
        q.push(make_pair(temp.first, temp.second + 1));
      }
    }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == 'o')
          board[i][j] = 'O';
      }
  }
};
