// https://leetcode.com/problems/remove-palindromic-subsequences/
// Easy

class Solution {
public:
    
    bool isPalindrome(string& s) {
        int l = 0, r = s.length()-1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    
    bool isPresent(string& s, char x) {
        
        for(char i : s) if(i == x) return true;
        return false;
    }

    int removePalindromeSub(string s) {
        
        if(s.length() == 0) return 0; // already empty          -> 0
        if(isPalindrome(s)) return 1; // already a palindrome   -> 1
        
        return isPresent(s, 'a') + isPresent(s, 'b');
    }
};