// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Medium, Amazon

class Solution {
public:
    
    bool binary_search(int start, int end, vector<int>& nums, int target) {
        
        if(start > end || start == end || end == start+1) {
            for(int i = start; i <= end; i++)
                if(nums[i] == target) return 1;
            return false;
        }
        
        int mid = start + (end-start)/2;
        if(nums[mid] == target) {
            return mid;
        }
        
        // left of mid or right of mid would be sorted
        bool leftSort  = (nums[start] <= nums[mid]);
        bool rightSort = (nums[mid] <= nums[end]);
        
        bool left = false, right = false;
        if(leftSort) {
            if(nums[start] <= target && target <= nums[mid]) {
                left = binary_search(start, mid, nums, target);
            }
            else 
                right = binary_search(mid, end, nums, target);
        }
        
        // If not Left side
        if(!left && !right) {
            if(nums[mid] <= target && target <= nums[end]) {
                right = binary_search(mid, end, nums, target);
            }
            else 
                left = binary_search(start, mid, nums, target);
        }
        
        return left || right;
    }
    
    int search(vector<int>& nums, int target) {
        
        return binary_search(0, nums.size()-1, nums, target);
    }
};
