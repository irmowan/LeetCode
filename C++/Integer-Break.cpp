class Solution {
 public:
  int integerBreak(int n) {
    if (n <= 1) return -1;
    int t = n / 6;
    long long s = 1;
    for (int i = 0; i < t; ++i) s *= 9;
    switch (n % 6) {
      case 0:
        break;
      case 1:
        s = s / 3 * 4;
        break;
      case 2:
        if (t > 0) s = s * 2;
        break;
      case 3:
        if (t > 0)
          s = s * 3;
        else
          s = 2;
        break;
      case 4:
        s = s * 4;
        break;
      case 5:
        s = s * 6;
        break;
      default:
        break;
    }
    return s;
  }
};
