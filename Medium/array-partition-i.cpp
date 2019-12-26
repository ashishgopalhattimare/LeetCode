// https://leetcode.com/problems/array-partition-i/
// Easy

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        // Maximum is always eliminated by the smaller element
        // in the pair making
        sort(nums.begin(), nums.end());
        
        int result = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            // hidden : min(nums[i], nums[i+1]) is always nums[i]
            result += nums[i];
        }
        return result;
    }
};