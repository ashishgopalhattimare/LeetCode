// https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int d, int dd) {
        long long int dividend = d;
        long long int divisor = dd;
        
        if(dividend == 0 || divisor == 0) return 0;
        
        bool negate = true;
        
        if((dividend < 0 && divisor < 0) || dividend > 0 && divisor > 0) negate = false;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long int count = 0;
        
        if(divisor == 1) count = dividend;
        else {
            while(dividend >= divisor) {
                dividend-=divisor;
                count++;
            }
        }
        
        if(negate) count = -1 * count;
        
        if(count > INT_MAX || count < INT_MIN) return INT_MAX;
        return count;
    }
};