// https://leetcode.com/problems/2-keys-keyboard/description/

class Solution {
public:
    int minSteps(int n) {
        
        // get the prime factors of n, they are the steps required
        // excluding 1 as we are starting with one 'A'

        // 24 = 2 * 2 * 2 * 3
        // each prime_factor(k) has : 1 copy and (k-1) paste involved 

        int val = 1;
        int steps = 0;
        for(int i = 2; i <= n; ) {
            if(n % i == 0) {
                steps += i;
                n/=i;
            }
            else i++;
        }
        
        return steps;
    }
};