// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>arr(nums.size(), 1);
        
        // iterate from j to i for each sub array
        // and if num[j] < num[i] -> then maximize arr[i] by 1
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    arr[i] = max(arr[i], arr[j] + 1);
                }
            }
        }
        
        int maxLen = 0;
        for(int i = 0; i < arr.size(); i++) {
            maxLen = max(maxLen, arr[i]);
        }
        
        return maxLen;
    }
};