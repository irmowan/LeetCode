class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> dict;
    vector<int> result;
    for (auto num : nums1) {
      dict[num]++;
    }
    for (auto num : nums2) {
      if (--dict[num] >= 0)
        result.push_back(num);
    }
    return result;
  }
};