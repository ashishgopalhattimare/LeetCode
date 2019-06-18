// https://leetcode.com/problems/counting-bits/
// DP, Get the Pattern

class Solution {
public:
    vector<int> countBits(int num) {
        
        int start = 0;
        vector<int>result(num+1, 0);
        for(int i = 1; i <= num; i++, start++) {
            if(floor(log2(i)) == ceil(log2(i))) {
                result[i] = 1;
                start = 0;
            }
            else {
                result[i] = result[start]+1;
            }
        }
        return result;
    }
};
