// first right interval

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(pair<int,int> &a, pair<int,int> &b)
{
	if(a.first == b.first) {
    	return a.second < b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    
    
    
    int binarySearch(vector<pair<int, int> >& ar, int start, int end, int x, int index)
    {
        if(start > end) return -1;
        
        if(end == start+1) {
            for(int i = start; i < ar.size(); i++) {
                if(ar[i].first >= x && ar[i].second != index) return ar[i].second;
            }
            return -1;
        }
        
        int mid = start + (end - start)/2;
        
        if(ar[mid].first <= x) {
            return binarySearch(ar, mid, end, x, index);
        }
        return binarySearch(ar, start, mid, x, index);
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        
        vector<pair<int, int> >ar;
        vector<int> V;
        
        if(intervals.size() == 1) {
            V.push_back(-1);
            return V;
        }
        
        for(int i = 0; i < intervals.size(); i++) {
            ar.push_back(make_pair(intervals[i].start, i));
        }
        sort(ar.begin(), ar.end(), compare);
        
        for(int i = 0; i < intervals.size(); i++) {
            V.push_back(binarySearch(ar, 0, ar.size()-1, intervals[i].end, i));
        }
        
        return V;
    }
};