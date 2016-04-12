/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    if (intervals.size() == 0) return ans;
    sort(
        intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) { return a.start < b.start; });
    Interval temp = intervals[0];

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start <= temp.end) {
        temp.end = max(temp.end, intervals[i].end);
      } else {
        ans.push_back(temp);
        temp = intervals[i];
      }
    }
    ans.push_back(temp);
    return ans;
  }
};
