// https://leetcode.com/problems/relative-ranks/
// Easy

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        
        vector<pair<int,int>>temp(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            temp[i] = make_pair(nums[i], i);
        }
        
        // Sort the temp according to score
        std::sort(temp.begin(), temp.end(), [](pair<int,int>& a, pair<int,int>& b) {
           return a.first > b.first; 
        });
        
        vector<string> result(nums.size());
        
        string medals[3] = {"Gold Medal","Silver Medal","Bronze Medal"};
        for(int i = 0; i < temp.size(); i++) {
            // First three are medalist
            if(i < 3) {
                result[temp[i].second] = medals[i];
            }
            // rest are simply rank
            else result[temp[i].second] = to_string(i+1);
        }
        
        return result;
    }
};
