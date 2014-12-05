//first sort intervals by the start of every interval if they are not equal,
//or the end if the starts are equal.
//Then merge the interval from the second to the end: If the start of the interval
//that will merged bigger than the end of the last merged interval, we just
//push_back, or else the end of the merged interval is the bigger of the two.
//One problem, when using sort algorithm in the library, we should define a 
//compare function myself, but cannot pass. So I have to overload operator < 
//in the sort algorithm.
bool operator < (const Interval &a1, const Interval &a2)
{
    if(a1.start == a2.start)
        return a1.end < a2.end;
    return a1.start < a2.start;
}
    
class Solution {
    
public:
    vector<Interval> merge(vector<Interval> &intervals) {

        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(res[res.size()-1].end >= intervals[i].start)
            {
                res[res.size()-1].end = max(res[res.size()-1].end, intervals[i].end);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
