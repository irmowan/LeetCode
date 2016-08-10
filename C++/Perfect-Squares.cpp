// refer to four-square-theorem & three-square-theorem:
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem
// https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
class Solution {
private:
  bool is_square(int n) {
    int sqrt_n = (int)(sqrt(n));
    return (sqrt_n * sqrt_n == n);
  }

public:
  int numSquares(int n) {
    // case 1: square number
    if (is_square(n)) {
      return 1;
    }
    // case 2: three-square-theorem
    // n can be represented as the sum of three squares of integers,
    // if and only if n is not the form:
    // n = 4^a*(8b+7) for integers a and b.
    while ((n & 3) == 0) {
      n >>= 2;
    }
    if ((n & 7) == 7) {
      return 4;
    }
    // case 3: the sum of two square
    int sqrt_n = (int)(sqrt(n));
    for (int i = 1; i <= sqrt_n; ++i) {
      if (is_square(n - i * i)) {
        return 2;
      }
    }
    // case 4: the remaining case
    return 3;
  }
};