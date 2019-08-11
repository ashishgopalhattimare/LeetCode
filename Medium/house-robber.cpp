// https://leetcode.com/problems/house-robber/
// Using Memoization Over subproblems
// Similar to Tree Problem

class Solution {
public:
    
    unordered_map<int,int>map;
    int robberHouse(vector<int>& nums, int index) {
        if(index >= nums.size()) return 0;
        
        if(map.find(index) != map.end()) {
            return map[index];
        }
        
        map[index] = max(nums[index] + robberHouse(nums, index+2), robberHouse(nums, index+1));
        
        return map[index];
    }
    
    int rob(vector<int>& nums) {
        return robberHouse(nums, 0);
    }
};
