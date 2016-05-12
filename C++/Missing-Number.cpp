class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = nums.size();
        long s = l * (l + 1) / 2;
        for (int i = 0; i < l; ++i) {
            s -= nums[i];
        }
        return s;
    }
};
