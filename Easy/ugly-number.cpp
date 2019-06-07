// https://leetcode.com/problems/ugly-number/
// Easy

class Solution {
public:
    bool isUgly(int num) {
        
        if(num == 0) return false;
        
        int divide[3] = {2,3,5};
        for(int i = 0; i != 3; i++) {
            while(num % divide[i] == 0) {
                num /= divide[i];
            }
        }
        return num == 1;
    }
};
