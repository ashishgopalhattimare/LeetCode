// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Easy

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int result = 0;
        
        for(int x : nums) {
            if((int)(log10(x)+1)%2 == 0) { // even digits
                result++;
            }
        }
        
        return result;
    }
};