class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> degree(numCourses, 0);
    queue<int> zeroPoint;
    vector<int> result;
    for (pair<int, int> prerequisite : prerequisites) {
      degree[prerequisite.first]++;
    }
    for (int i = 0; i < numCourses; ++i) {
      if (degree[i] == 0)
        zeroPoint.push(i);
    }
    while (!zeroPoint.empty()) {
      int key = zeroPoint.front();
      zeroPoint.pop();
      result.push_back(key);
      for (pair<int, int> prerequisite : prerequisites) {
        if (prerequisite.second == key) {
          if (--degree[prerequisite.first] == 0) {
            zeroPoint.push(prerequisite.first);
          };
        }
      }
    }
    if (result.size() < numCourses) {
      return false;
    }
    return true;
  }
};