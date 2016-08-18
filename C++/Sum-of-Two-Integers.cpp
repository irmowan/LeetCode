class Solution {
public:
  int getSum(int a, int b) {
    int sum = 0;
    while (b != 0) {
      sum = a ^ b;      // Calculate sum ignore carry
      b = (a & b) << 1; // Calculate carry
      a = sum;
    }
    return sum;
  }
};