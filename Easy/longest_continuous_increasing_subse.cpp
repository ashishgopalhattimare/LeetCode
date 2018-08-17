// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

// O(n) space and time complexity

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        vector<int>result(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) {
                result[i] = result[i-1]+1;
            }
        }
        
        int maxim = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxim = max(maxim, result[i]);
        }
        
        return maxim;
    }
};