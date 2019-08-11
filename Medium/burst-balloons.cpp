// https://leetcode.com/problems/burst-balloons/
// Hard, Flipkart

class Solution {
public:
    
    int getB(int i, vector<int>& nums) {
        if(i < 0 || i >= nums.size()) return 1;
        return nums[i];
    }
    
    int maxCoins(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        vector<vector<int>> DP = vector<vector<int>>(nums.size(), vector<int>(nums.size(), 0));
        
        // Base Case
        for(int i = 0; i < nums.size(); i++) {
            DP[i][i] = getB(i-1, nums) * nums[i] * getB(i+1, nums);            
        }
        
        int low, high;
        int LEFT, RIGHT;
        for(int j = 1; j < nums.size(); j++) {
            for(int i = 0; i+j < nums.size(); i++) {
                low = i; high = i+j;
                // If kth ballon is the last one to be burst in the subarray from low to high
                for(int k = low; k <= high; k++) {
                    
                    LEFT = (low == k) ? 0 : DP[low][k-1];
                    RIGHT = (high == k) ? 0 : DP[k+1][high];
                    
                    DP[low][high] = max(DP[low][high], LEFT + RIGHT + 
                                        getB(low-1, nums)*nums[k]*getB(high+1, nums));
                }
            } 
        }
        
        return DP[0][nums.size()-1];
    }
};
