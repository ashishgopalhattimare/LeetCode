// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size()/2]; // bring the elements close to the median of the array
        
        int moves = 0;
        for(int i = 0; i < nums.size(); i++) {
            moves += abs(median - nums[i]);
        }
        
        return moves;
    }
};