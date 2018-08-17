// https://leetcode.com/problems/find-pivot-index/description/

/**
O(n) solution with O(n) space
**/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        if(nums.size() == 0) return -1;
        
        vector<int> sum(nums.size());
        
        int s = 0;
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            sum[i] = s;
        }
        
        int left, right;
        for(int i = 0; i < nums.size(); i++) {
            left = sum[i] - nums[i];
            right = sum[nums.size()-1] - sum[i];
            
            if(left == right) return i;
        }
        return -1;
    }
};