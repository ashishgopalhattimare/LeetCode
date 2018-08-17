// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int value;
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] + 1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            value = abs(nums[i]);
            
            if(value > nums.size()) continue;
            
            nums[value-1] = -1 * abs(nums[value-1]);
        }
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] > 0) return i;
        }
        
        return nums.size();
    }
};