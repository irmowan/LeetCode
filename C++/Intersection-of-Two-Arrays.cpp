class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty())
      return nums1;
    if (nums2.empty())
      return nums2;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int l1 = nums1.size(), l2 = nums2.size();
    int i1 = 0, i2 = 0;
    vector<int> result;
    while (i1 < l1 && i2 < l2) {
      if (nums1[i1] == nums2[i2]) {
        result.push_back(nums1[i1]);
        i1++, i2++;
      } else if (nums1[i1] > nums2[i2]) {
        i2++;
      } else {
        i1++;
      }
      while (i1 > 0 && i1 < l1 && nums1[i1] == nums1[i1 - 1])
        i1++;
      while (i2 > 0 && i2 < l2 && nums2[i2] == nums2[i2 - 1])
        i2++;
    }
    return result;
  }
};
