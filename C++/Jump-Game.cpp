class Solution {
public:
  bool canJump(vector<int> &nums) {
    int l = nums.size();
    int reach = 0;
    for (int i = 0; i < l && i <= reach; ++i)
      reach = max(reach, i + nums[i]);
    return reach >= l - 1;
  }
};