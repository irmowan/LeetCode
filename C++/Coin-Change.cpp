class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = -1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] == i) {
                    dp[i] = 1;
                    continue;
                }
                if (i - coins[j] > 0 && dp[i - coins[j]] > 0) {
                    int temp = dp[i - coins[j]] + 1;
                    if (dp[i] <= 0 || temp < dp[i])
                        dp[i] = temp;
                    continue;
                }
                if (dp[i] == 0)
                    dp[i] = -1;
            }
        }
        return dp[amount];
    }
};
