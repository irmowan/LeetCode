class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
      // Pruning! Avoid TLE.
      if (isPrime[i] == false)
        continue;
      for (int j = 2; j <= n / i; ++j) {
        isPrime[i * j] = false;
      }
    }
    int ans = count(isPrime.begin(), isPrime.end(), true);
    return ans;
  }
};