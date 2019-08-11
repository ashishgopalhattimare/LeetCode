// https://leetcode.com/problems/single-number-iii/
// Medium

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        vector<int>result;
        for(auto itr : map) {
            if(itr.second == 1) result.push_back(itr.first);
        }
        
        return result;
    }
};
