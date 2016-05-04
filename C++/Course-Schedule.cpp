class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<int> courses[numCourses];
    for (auto &e : prerequisites) courses[e.second].push_back(e.first);
    vector<bool> visiting(numCourses, false);
    vector<bool> visited(numCourses, false);
    for (int i = 0; i < prerequisites.size(); ++i) {
      if (!visited[i] && !dfs(courses, visiting, visited, i)) return false;
    }
    return true;
  }
  bool dfs(vector<int> courses[], vector<bool> &visiting, vector<bool> &visited,
           int i) {
    visiting[i] = true;
    for (auto &x : courses[i]) {
      if (visiting[x] || !dfs(courses, visiting, visited, x)) return false;
    }
    visiting[i] = false;
    visited[i] = true;
    return true;
  }
};
