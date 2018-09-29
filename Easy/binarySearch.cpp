// https://leetcode.com/problems/binary-search/description/

class Solution {
public:
    
    int binarySearch(int start, int end, vector<int>& nums, int target)
    {
        if(start > end) return -1;
        
        if(end == start+1) {
            if(nums[start] == target) return start;
            if(nums[end] == target) return end;
            
            return -1;
        }
        else if(end == start) {
            if(nums[start] == target) return start;
            
            return -1;
        }
        
        int mid = start + (end - start) / 2;
        
        if(nums[mid] == target) return mid;
        
        if(target > nums[mid]) {
            return binarySearch(mid, end, nums, target);
        }
        return binarySearch(start, mid, nums, target);
    }
    
    int search(vector<int>& nums, int target) {
        
        return binarySearch(0, nums.size()-1, nums, target);
    }
};
