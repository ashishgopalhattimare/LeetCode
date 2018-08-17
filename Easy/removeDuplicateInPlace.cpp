// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int index = 0;
        if(nums.size() == 0) return index;
        
        int prev = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(prev != nums[i]) {
                nums[index++] = prev;
            }
            
            prev = nums[i];
        }
        
        nums[index++] = prev;
        
        return index;
    }
};