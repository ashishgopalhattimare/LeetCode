// https://leetcode.com/problems/contiguous-array/
// Medium
// Convert all zeros to -1, and then find the longest subarray with sum 0
// Complexity : O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>map;
        int sum = 0, longest = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) sum--;
            else sum++;
            
            if(sum == 0) longest = i+1;
            else {
                if(map.find(sum) != map.end()) {
                    longest = max(longest, i-map[sum]);
                }
                else map[sum] = i;
            }
        }
        
        return longest;
    }
};
