class Solution {
public:
  int nthUglyNumber(int n) {
    int idx2 = 0, idx3 = 0, idx5 = 0;
    int candidate1, candidate2, candidate3;
    vector<int> ugly(n, 0);

    ugly[0] = 1;
    for (int i = 1; i < n; ++i) {
      candidate1 = ugly[idx2] * 2;
      candidate2 = ugly[idx3] * 3;
      candidate3 = ugly[idx5] * 5;
      int min = candidate1 < candidate2 ? candidate1 : candidate2;
      min = min < candidate3 ? min : candidate3;
      ugly[i] = min;
      if (min == candidate1)
        idx2++;
      if (min == candidate2)
        idx3++;
      if (min == candidate3)
        idx5++;
    }
    return ugly[n - 1];
  }
};
