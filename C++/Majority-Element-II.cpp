class Solution {
private:
  int exist(int x, int bucket[]) {
    // return index when find x;
    if (bucket[0] == x)
      return 0;
    if (bucket[1] == x)
      return 1;
    if (bucket[2] == x)
      return 2;
    return -1;
  }
  int hasEmpty(int cnt[]) {
    if (cnt[0] == 0)
      return 0;
    if (cnt[1] == 0)
      return 1;
    if (cnt[2] == 0)
      return 2;
    return -1;
  }

public:
  vector<int> majorityElement(vector<int> &nums) {
    int bucket[3];
    int cnt[3];
    memset(bucket, -1, sizeof(bucket));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < nums.size(); ++i) {
      int index = exist(nums[i], bucket);
      if (index != -1) {
        cnt[index]++;
      } else {
        int flag = hasEmpty(cnt);
        if (flag >= 0) {
          bucket[flag] = nums[i];
          cnt[flag]++;
        } else {
          for (int j = 0; j < 3; ++j) {
            cnt[j]--;
            if (cnt[j] == 0)
              bucket[j] = -1;
          }
        }
      }
    }
    int sum[3] = {0};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < 3; ++j)
        if (nums[i] == bucket[j])
          sum[j]++;
    }
    vector<int> ans;
    int t = 0;
    for (int i = 0; i < 3; ++i)
      if (cnt[i] > 0 && sum[i] > nums.size() / 3) {
        ans.push_back(bucket[i]);
      }
    return ans;
  }
};
