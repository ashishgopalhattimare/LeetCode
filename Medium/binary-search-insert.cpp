// Binary Search - if not found, insert index return
// Mock Test

class Solution {
public:
    
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        
        if(end == start+1 || end == start) {
            if(nums[start] == target) return start;
            return end;
        }
        
        int mid = (start + end)/2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[mid] > target) {
            return binarySearch(nums, start, mid, target);
        }
        return binarySearch(nums, mid, end, target);
    }
    
    int searchInsert(vector<int>& nums, int target) {
        
        if(target < nums[0]) return 0;
        if(target > nums[nums.size()-1]) return nums.size();
        
        return binarySearch(nums, 0, nums.size(), target);
    }
};
