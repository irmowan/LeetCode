class Solution {
private:
  int min(vector<int> &candidate) {
    int index = 0;
    int min = candidate[0];
    for (int i = 1; i < candidate.size(); ++i) {
      if (candidate[i] < min) {
        min = candidate[i];
        index = i;
      }
    }
    return index;
  }

public:
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    int num = primes.size();
    vector<int> index(num, 0);
    vector<int> candidate(num, 0);
    vector<int> ugly(n, 0);
    int last_update = 0;

    ugly[0] = 1;
    for (int i = 0; i < num; ++i)
      candidate[i] = primes[i];

    for (int i = 1; i < n; ++i) {
      int min_index = min(candidate);

      while (ugly[i - 1] == candidate[min_index]) {
        index[min_index]++;
        candidate[min_index] = ugly[index[min_index]] * primes[min_index];
        min_index = min(candidate);
      }

      ugly[i] = candidate[min_index];
      index[min_index]++;
      candidate[min_index] = ugly[index[min_index]] * primes[min_index];
    }
    return ugly[n - 1];
  }
};
