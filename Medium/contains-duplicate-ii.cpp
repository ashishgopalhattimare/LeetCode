// https://leetcode.com/problems/contains-duplicate-ii/
// Easy

// Given an array of integers and an integer k, find out whether 
// there are two distinct indices i and j in the array such that 
// nums[i] = nums[j] and the absolute difference between i and j 
// is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int>prev;
        for(int i = 0; i < nums.size(); i++) {
            if(prev.find(nums[i]) != prev.end()) {
                 if(i - prev[nums[i]] <= k) return true;
            }
            prev[nums[i]] = i;
        }
        return false;
    }
};
