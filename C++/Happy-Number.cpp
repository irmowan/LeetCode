class Solution {
private:
  int go(int num) {
    int result = 0;
    while (num > 0) {
      result += (num % 10) * (num % 10);
      num /= 10;
    }
    return result;
  }

public:
  bool isHappy(int n) {
    unordered_set<int> set;
    while (set.find(n) == set.end()) {
      set.insert(n);
      n = go(n);
      if (n == 1)
        return true;
    }
    return false;
  }
};