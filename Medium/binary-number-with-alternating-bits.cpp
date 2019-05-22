// https://leetcode.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1, bit;
        while(n) {
            bit = n%2;
            if(prev == bit) return false;
            prev = bit;
            n/=2;
        }
        return true;
    }
};
