// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    long l = 1;
    long r = n;
    long mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (isBadVersion(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return r;
  }
};
