class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m > n)
      return findMedianSortedArrays(nums2, nums1);
    if (m == 0)
      return (double)(nums2[(n - 1) / 2] + nums2[n / 2]) / 2;
    int left = 0;
    int right = m;
    int max_left, min_right;
    while (left <= right) {
      // notice that i,j means how many, not index.
      int i = (left + right) / 2;
      int j = (m + n + 1) / 2 - i;
      int l1, l2, r1, r2;

      l1 = i > 0 ? nums1[i - 1] : INT_MIN;
      l2 = j > 0 ? nums2[j - 1] : INT_MIN;
      r1 = i < m ? nums1[i] : INT_MAX;
      r2 = j < n ? nums2[j] : INT_MAX;
      if (l1 > r2)
        right = i - 1;
      else if (l2 > r1)
        left = i + 1;
      else {
        if ((m + n) % 2 == 0)
          return (double)(max(l1, l2) + min(r1, r2)) / 2;
        return max(l1, l2);
      }
    }
    return 0;
  }
};