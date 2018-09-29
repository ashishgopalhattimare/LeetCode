// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int maxElement = INT_MIN;
        int index = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(maxElement < nums[i]) {
                maxElement = nums[i];
                index = i;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(i == index) continue;
            
            if(maxElement < 2 * nums[i]) {
                return -1;
            }
        }
        
        return index;
    }
};
