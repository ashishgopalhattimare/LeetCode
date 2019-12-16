// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Easy

class Solution {
public:
    int subtractProductAndSum(int n) {
        
        long long prod = 1, sum = 0;
        
        int temp = n;
        while(temp) {
            prod *= (temp%10);
            sum += (temp%10);
            
            temp/=10;
        }
        
        return prod - sum;
    }
};