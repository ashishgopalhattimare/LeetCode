// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Medium, Amazon

class Solution {
public:
    
    int binary_search(int start, int end, vector<int>& nums, int target) {
        if(start > end || start == end || end == start+1) {
            for(int i = start; i <= end; i++)
                if(nums[i] == target) return i;
            return -1;
        }
        
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        
        // left of mid or right of mid would be sorted
        bool leftSort  = (nums[start] < nums[mid]);
        bool rightSort = (nums[mid] < nums[end]);
        
        if(leftSort) {
            if(nums[start] <= target && target <= nums[mid]) {
                return binary_search(start, mid-1, nums, target);
            }
            return binary_search(mid+1, end, nums, target);
        }
        else {
            if(nums[mid] <= target && target <= nums[end]) {
                return binary_search(mid+1, end, nums, target);
            }
            return binary_search(start, mid-1, nums, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        
        return binary_search(0, nums.size()-1, nums, target);
    }
};

// 17
