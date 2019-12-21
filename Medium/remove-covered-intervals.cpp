// https://leetcode.com/problems/remove-covered-intervals/
// Medium

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        list<vector<int>>ll;
        vector<int> y;
        
        for(vector<int>& x : intervals) {
            
            if(ll.empty()) ll.push_back(x);
            else {
                y = ll.back();
                if(y[0] <= x[0] && x[1] <= y[1]) {
                    continue;
                }
                ll.push_back(x);
            }
        }
        
        return ll.size();
    }
};