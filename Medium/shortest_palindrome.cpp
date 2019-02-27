// https://leetcode.com/problems/shortest-palindrome/description/
// Manachar's Algorithm - Palindromic Orbital search for all possible palindrome

class Solution {
public:
    
    int index, maxLength;
    bool found = false;
    
    bool palindrome(string s) {
        for(int i = 0, j = s.length()-1; i < j; i++, j--) {
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
    void palindromeOrbit(int l, int r, string s)
    {
        while(l >= 0 && r < s.length()) {
            if(s[l] == s[r]) {
                if(l == 0) {
                    
                    found = true;
                    
                    // if the palindrome check orbit has reached the left most end,
                    // then the minimum right most remaining characters has to be
                    // added to the beginning to make it palindrome
                    if(maxLength > s.length()-r) {
                        maxLength = s.length()-r;
                        index = r+1;
                    }
                }
                l--; r++;
            }
            else { break; }
        }
    }
    
    string shortestPalindrome(string s) {
        
        // check if the string is already a palindrome
        if(palindrome(s)) return s;
        
        maxLength = INT_MAX;
        int l, r;
        for(int i = 0; i < s.length(); i++) {
            
            palindromeOrbit(i-1, i+1, s);
            palindromeOrbit(i, i+1, s);
        }
        
        string result = "";
        if(found) {
            // Append the minimum remaining characters to make it palindrome
            for(int i = s.length()-1; i >= index; i--) {
                result.push_back(s[i]);
            }
        }
        else {
            // append the entire string except the first character
            for(int i = s.length()-1; i ; i--) {
                result.push_back(s[i]);
            }
        }
        
        return result + s;
    }
};
