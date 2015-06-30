/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //two points: 1, control the start and end of the index 
 //2, the terminator of control condition
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        if(intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start)
        {
            res.push_back(intervals[i]);
            ++i;
        }
        if(i < intervals.size())
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
        }
        while(i < intervals.size() && intervals[i].start <= newInterval.end)
        {
            newInterval.end = max(intervals[i].end, newInterval.end);
            ++i;
        }
        res.push_back(newInterval);
        while(i < intervals.size())
        {
            res.push_back(intervals[i]);
            ++i;
        }
        return res;
    }
};
