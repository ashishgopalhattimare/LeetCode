// Mock Test, Facebook interview
// Level 3

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return {};
        
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
           return a < b; 
        });
        
        vector<vector<int>>result = { intervals[0] };
        
        int k = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(result[k][1] >= intervals[i][0]) {
                result[k][1] = max(result[k][1], intervals[i][1]);
                continue;
            }
            result.push_back(intervals[i]);
            k++;
        }
        return result;
    }
};
