// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// Easy

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int>temp = nums, result(nums.size());
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < nums.size(); i++) {
            result[i] = lower_bound(temp.begin(), 
            	temp.end(), nums[i]) - temp.begin();
        }
        
        return result;
    }
};