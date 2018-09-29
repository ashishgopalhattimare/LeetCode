// https://leetcode.com/problems/prime-palindrome

class Solution {
public:
    
    bool palindromic(int num)
    {
        int f1 = num;
        int f2 = 0;
        
        while(num) {
            f2 = f2*10 + (num%10);
            num/=10;
        }
        return (f1 == f2);
    }
    
    bool isPrime(int num) {
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
    
    int primePalindrome(int N) {
    
        int LIMIT = 9989900;
        
        if(N >= LIMIT) return 100030001;
        
        int i;
        for(i = 2; i < LIMIT; i++) {
            if(i >= N && palindromic(i) && isPrime(i)) {
                break;
            }
        }
        return i;
    }
};