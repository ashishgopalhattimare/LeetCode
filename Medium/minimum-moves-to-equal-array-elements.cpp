// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Easy

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minEle = INT_MAX;
        int result = 0;
        
        for(int x : nums) minEle = min(minEle, x);
        for(int x : nums) result += abs(minEle-x);
        
        return result;
    }
};