// https://leetcode.com/problems/add-digits/solution/

class Solution {
public:
    int addDigits(int num) {
        
        int sum = 0;
        
        while(num) {
            sum += (num%10);
            sum = sum/10 + sum%10;
            num/=10;
        }
        
        // if(num && num % 9 == 0) return 9;
        // return num % 9;
        
        return sum;
    }
};