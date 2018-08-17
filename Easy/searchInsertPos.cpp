https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        if(end == start+1) {
            if(target <= nums[start]) return start;
            
            if(target <= nums[end]) return end;
            if(target > nums[end]) return end+1;
        }
        else if(start == end) {
            if(target <= nums[end]) return end;
            if(target > nums[end]) return end+1;
        }
        
        int mid = start + (end - start)/2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[mid] < target) {
            return binarySearch(nums, mid, end, target);
        }
        return binarySearch(nums, start, mid, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return 0;
        
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};