// https://leetcode.com/contest/weekly-contest-148/problems/decrease-elements-to-make-array-zigzag/
// Medium
// Linear Approach (no modify list)

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        
        if(nums.size() <= 1) return 0;
        
        int cost, minimCost = INT_MAX;
        int minElem;
        
        cost = 0;
        for(int i = 1; i < nums.size(); i+=2) {
            if(i == nums.size()-1) {
                if(nums[i-1] <= nums[i]) {
                    cost += (abs(nums[i-1]-nums[i])+1);
                }
            }
            else {
                minElem = min(nums[i-1], nums[i+1]);
                if(nums[i] >= minElem) {
                    cost += (abs(minElem-nums[i])+1);
                }
            }
        }
        
        minimCost = min(minimCost, cost);
        
        cost = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            if(i == nums.size()-1) {
                if(nums[i-1] <= nums[i]) {
                    cost = cost + abs(nums[i-1]-nums[i])+1;
                }
            }
            else if(i == 0) {
                if(nums[i] >= nums[i+1]) {
                    cost += (abs(nums[i+1]-nums[i])+1);
                }
            }
            else {
                minElem = min(nums[i-1], nums[i+1]);
                if(nums[i] >= minElem) {
                    cost += (abs(minElem-nums[i])+1);
                }
            }
        }
        
        minimCost = min(minimCost, cost);
        
        return minimCost;
    }
};
