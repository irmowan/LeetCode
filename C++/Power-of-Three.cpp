class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n > 1) {
      while (n % 3 == 0)
        n /= 3;
    }
    return n == 1;
  }
  bool isPowerOfThree_2(int n) {
    double l = log10(n) / log10(3);
    return ((l - int(l)) == 0) ? true : false;
  }
};
