// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        if(nums.size() <= 1) return 0;
        
        int start, end;
        int duplicate;
        
        // starting sort
        duplicate = -1;
        for(start = 0; start < nums.size()-1; start++) {
            if(nums[start] > nums[start+1]) {
                if(duplicate != -1) {
                    start = duplicate;
                }
                break;
            }
            else if(nums[start] == nums[start+1]) {
                if(duplicate == -1) {
                    duplicate = start;
                }
            }
            else {
                duplicate = -1;
            }
        }
        
        if(start == nums.size()-1) return 0;
        
        duplicate = -1;
        for(end = nums.size()-1; end > 0; end--) {
            if(nums[end-1] > nums[end]) {
                if(duplicate != -1) {
                    end = duplicate;
                }
                break;
            }
            else if(nums[end-1] == nums[end]) {
                if(duplicate == -1) {
                    duplicate = end;
                }
            }
            else {
                duplicate = -1;
            }
        }
        
        int minim = INT_MAX, maxim = INT_MIN;
        
        for(int i = start; i <= end; i++) {
            minim = min(minim, nums[i]);
            maxim = max(maxim, nums[i]);
        }
        
        int resEnd = end, resStart = start;
        
        for(int i = end+1; i < nums.size(); i++) {
            if(maxim == nums[i]) {
                resEnd = i-1;
                break;
            }
            else if(maxim > nums[i]) {
                resEnd = i;
            }
        }
        for(int i = start-1; i >= 0; i--) {
            if(minim == nums[i]) {
                resStart = i+1;
                break;
            }
            else if(minim < nums[i]) {
                resStart = i;
            }
            start++;
        }
        
        return resEnd - resStart +1;
    }
};