class Solution {
public:
  int minPatches(vector<int> &nums, int n) {
    int ans, i;
    long top;
    int len = nums.size();
    top = 0;
    ans = 0;
    i = 0;
    while (top < n) {
      if (i < len && nums[i] <= top + 1) {
        top = top + nums[i];
        i++;
      } else {
        ans++;
        top = top * 2 + 1;
      }
    }
    return ans;
  }
};
