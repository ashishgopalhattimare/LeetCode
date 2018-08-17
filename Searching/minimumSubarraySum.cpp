// https://leetcode.com/problems/minimum-size-subarray-sum/description/

// minimum range where sum >= s

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int j = 0;
        int sum = nums[0];
        
        if(sum >= s) return 1; // sum >= s
        int minRange = INT_MAX;
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            
            if(sum >= s) { // sum  >= s
                if(sum >= s && minRange > (i-j+1)) { // sum >= s -> might be the result
                    minRange = i-j+1;
                }
                while(sum > s) { 
                    sum -= nums[j];
                    j++;
                    
                    if(sum >= s && minRange > (i-j+1)) { // sum >= s -> might be the result
                        minRange = i-j+1;
                    }
                }
            }
        }
        
        if(minRange == INT_MAX) return 0;
        return minRange;
    }
};

/**





**/