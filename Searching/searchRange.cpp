// https://leetcode.com/problems/search-for-a-range/description/

class Solution {
public:
    
    int binarySearch1(vector<int>& nums, int start, int end, int target)
    {
        if(start > end) return -1;
        
        if(end == start+1) {
            if(nums[start] == target) return start;
            if(nums[end] == target) return end;
            
            return -1;
        }
        
        if(start == end) {
            if(nums[start] == target) return start;
            return -1;
        }
        
        int mid = start + (end - start)/2;
        if(target <= nums[mid]) {
            return binarySearch1(nums, start, mid, target);
        }
        return binarySearch1(nums, mid, end, target);
    }
    
    int binarySearch2(vector<int>& nums, int start, int end, int target)
    {
        if(start > end) return -1;
        
        if(end == start+1) {
            if(nums[end] == target) return end;
            if(nums[start] == target) return start;
            
            return -1;
        }
        
        if(start == end) {
            if(nums[start] == target) return start;
            return -1;
        }
        
        int mid = start + (end - start)/2;
        if(target >= nums[mid]) {
            return binarySearch2(nums, mid, end, target);
        }
        return binarySearch2(nums, start, mid, target);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> V;
        
        int first = binarySearch1(nums, 0, nums.size()-1, target);
        V.push_back(first);
        
        if(first == -1) {
            V.push_back(-1);
        }
        else {
            V.push_back(binarySearch2(nums, first, nums.size()-1, target));   
        }
        
        return V;
    }
};