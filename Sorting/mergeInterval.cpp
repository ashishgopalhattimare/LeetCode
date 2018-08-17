// https://leetcode.com/problems/merge-intervals/description/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comparator(Interval &a, Interval &b)
{
    if(a.start == b.start) {
        return a.end < b.end;
    }
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval>v;
        if(intervals.size() == 0) {
            return v;
        }
        
        sort(intervals.begin(), intervals.end(), comparator);
        
        Interval A(intervals[0].start, intervals[0].end);
        v.push_back(A);
        
        int curr = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(v[curr].end >= intervals[i].start) {
                v[curr].end = max(v[curr].end, intervals[i].end);
            }
            else {
                Interval A(intervals[i].start, intervals[i].end);
                v.push_back(A);
                curr++;
            }
        }
        
        return v;
    }
};
