// https://leetcode.com/problems/132-pattern/
// Medium

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        if(nums.size() == 0) return false;
        
        // i is minimum among all values
        // j is largest
        // k is mid
        
        int first = nums[0], second, third;
        for(int j = 1; j < nums.size(); j++) {
            
            // we may take first to the minimum encountered
            first = min(first, third = nums[j]);
            if(first == third) continue;
            for(int k = j+1; k < nums.size(); k++) {
                
                second = nums[k];
                if(first < second && second < third)
                    return true;
            }
        }
        return false;
    }
};
