// https://leetcode.com/contest/weekly-contest-129/problems/smallest-integer-divisible-by-k/
// division visualization please

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        
        if(K%2==0 || K%5==0) return -1;
        
        int result = 0;
        for(int n = 1; n <= K; n++) {
            result = (result*10+1) % K;
            if(!result) return n;
        }
        return -1;
    }
};
