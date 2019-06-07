// https://leetcode.com/problems/house-robber/
// Maximum sum add no two adjacent included

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int incl = nums[0];
        int excl = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            int exclude = max(incl, excl); // if current number of excluded, what is the maximum
            incl = excl + nums[i]; // since incl cannot be used, use excl with current num[i]
            excl = exclude; // excl is the exclude of the num[i]
        }
        return max(incl, excl);
    }
};
