/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
  int maxPoints(vector<Point> &points) {
    int result = 0;
    for (int i = 0; i < points.size(); ++i) {
      unordered_map<double, int> count;
      int samePoint = 1;
      for (int j = i + 1; j < points.size(); ++j) {
        if (points[i].x == points[j].x && points[i].y == points[j].y) {
          samePoint++;
        } else if (points[i].x == points[j].x) {
          count[INT_MAX]++;
        } else {
          double slope = double(points[j].y - points[i].y) /
                         double(points[j].x - points[i].x);
          count[slope]++;
        }
      }
      int maxCount = 0;
      for (auto it = count.begin(); it != count.end(); ++it) {
        maxCount = max(maxCount, it->second);
      }
      maxCount += samePoint;
      result = max(result, maxCount);
    }
    return result;
  }
};