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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int len = intervals.size();
    int start, end, start_value, end_value, start_flag, end_flag;
    start = end = start_flag = end_flag = -1;
    if (len == 0) {
      intervals.push_back(newInterval);
      return intervals;
    }
    for (int i = 0; i < len; ++i) {
      if (start == -1) {
        if (intervals[i].start <= newInterval.start &&
            intervals[i].end >= newInterval.start) {
          start = i;
          start_flag = 1;
        } else if (intervals[i].start > newInterval.start) {
          start = i;
          start_flag = 0;
        }
      }
      if (end == -1) {
        if (intervals[i].start <= newInterval.end &&
            intervals[i].end >= newInterval.end && end == -1) {
          end = i;
          end_flag = 1;
        } else if (intervals[i].start > newInterval.end) {
          end = i;
          end_flag = 0;
        }
      }
    }
    if (start == -1) {
      start_flag = 2;
    }
    if (end == -1) {
      end_flag = 2;
    }
    start_value = start_flag == 1 ? intervals[start].start : newInterval.start;
    end_value = end_flag == 1 ? intervals[end].end : newInterval.end;
    Interval insertInterval(start_value, end_value);

    // Here, index means the index of the erased interval.
    // flag means whether the begin/end is in the existed interval.
    // value means the values of the new interval.
    // cout << "index:  " << start << " " << end << endl;
    // cout << "flag:   " << start_flag << " " << end_flag << endl;
    // cout << "value:  " << start_value << " " << end_value << endl;

    auto it_start = intervals.begin() + start;
    auto it_end = intervals.begin() + end;
    switch (end_flag) {
    case 0:
      if (end > start)
        intervals.erase(it_start, it_end);
      intervals.insert(it_start, insertInterval);
      break;
    case 1:
      intervals.erase(it_start, it_end + 1);
      intervals.insert(it_start, insertInterval);
      break;
    case 2:
      if (start >= 0) {
        intervals.erase(it_start, intervals.end());
        intervals.insert(it_start, insertInterval);
      } else {
        intervals.push_back(insertInterval);
      }
      break;
    }
    return intervals;
  }
};
