// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    
    bool isPalin(string str, int l, int r)
    {
        while(l < r) {
            if(str[l] != str[r]) return false;
            l++; r--;
        }
        
        return true;
    }
    
    bool isPalindrome1(string str, int l, int r)
    {
        int miss = 0;
        while(l < r) {
            if(str[l] != str[r]) {
                
                if(miss == 1) return false;
                
                if(miss == 0) {
                    miss = 1;
                    l++;
                    
                    continue;
                }
                return false;
            }
            l++; r--;
        }
        
        return true;
    }
    
    bool isPalindrome2(string str, int l, int r)
    {
        int miss = 0;
        while(l < r) {
            if(str[l] != str[r]) {
                
                if(miss == 1) return false;
                
                if(miss == 0) {
                    miss = 1;
                    r--;
                    
                    continue;
                }
                return false;
            }
            l++; r--;
        }
        
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int len = s.length();
        if(isPalin(s, 0, len-1)) {
            return true;
        }
        
        if(len == 2) return true;
        
        if(isPalindrome1(s, 0, len-1)) {
            return true;
        }
        
        if(isPalindrome2(s, 0, len-1)) {
            return true;
        }
        
        return false;
    }
};