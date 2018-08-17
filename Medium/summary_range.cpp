// https://leetcode.com/problems/summary-ranges/description/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> result;
        string element;
        
        if(nums.size() == 0) return result;
        
        int start, end;
        
        start = end= nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == end + 1) {
                end = nums[i];
            }
            else {
                if(start == end) {
                    element = to_string(start);
                }
                else {
                    element = to_string(start) + "->" + to_string(end);    
                }
                result.push_back(element);
                start = end= nums[i];
            }
        }
        if(start == end) {
            element = to_string(start);
        }
        else {
            element = to_string(start) + "->" + to_string(end);        
        }
        result.push_back(element);
        
        return result;
    }
};