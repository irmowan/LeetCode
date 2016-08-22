class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int min = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] > min && prices[i] - min > ans) {
        ans = prices[i] - min;
      }
      if (prices[i] < min) {
        min = prices[i];
      }
    }
    return ans;
  }
};