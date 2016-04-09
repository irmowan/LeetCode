// This code is in Hihocoder, the problem of Microsoft 2016 interview.

#include <iostream>
#include <string>

#define  MAX 102

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char map[MAX][MAX];
    int dp[MAX][MAX][2];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) map[i][j] = s[j];
    }
    int Max = 10000;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                dp[i][j][0] = (map[i][j] == 'b');
                dp[i][j][1] = (map[i][j] == 'b') + m > 2 ? (map[0][1] != 'b') : 0;
                continue;
            }
            int up = Max, left = Max;
            int tmp = 0;
            for (int k = i - 1; k >= 0; --k) {
                up = min(up, dp[k][j][1] + tmp);
                if (map[k][j] == 'b') tmp++;
            }
            tmp = 0;
            for (int k = j - 1; k >= 0; --k) {
                left = min(left, dp[i][k][0] + tmp);
                if (map[i][k] == 'b') tmp++;
            }
            if (map[i][j] == 'b') left++, up++;
            if (j < m - 1 && map[i][j + 1] != 'b') left++;
            if (i < n - 1 && map[i + 1][j] != 'b') up++;
            dp[i][j][0] = up;
            dp[i][j][1] = left;
        }
    }
    cout << min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
}
