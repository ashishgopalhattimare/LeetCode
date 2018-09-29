// https://leetcode.com/problems/binary-gap/

class Solution {
public:
    int binaryGap(int n) {
        if(n == 0) return 0;
        
        if(n == pow(2, static_cast<int>(log10(n)/log10(2)))) return 0;
        
        int maxim = INT_MIN, f1 = -1;
        
        int k = 0;
        while(n) {
            if(n%2) {
                if(f1 == -1) f1 = k;
                else {
                    maxim = max(maxim, k - f1);
                    f1 = k;
                }
            }
            n/=2;
            k++;
        }
        
        return maxim;
    }
};