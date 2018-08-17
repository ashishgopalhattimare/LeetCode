// https://leetcode.com/problems/detect-capital/submissions/1class Solution {
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
                    
                    l++;
                    miss = 1;
                    
                    continue;
                    
                }
                else return false;
            }
            
            l++;
            r--;
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
                    
                    r--;
                    miss = 1;
                    
                    continue;
                    
                }
                else return false;
            }
            
            l++;
            r--;
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

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if(word.length() == 0) return true;
        if(word.length() == 1) return true;
        
        bool first = isupper(word[0]);
        bool second = isupper(word[1]);
        
        if(first == false && second == true) return false;
        
        for(int i = 2; i < word.length(); i++) {
            if(isupper(word[1]) != isupper(word[i])) return false;
        }
        
        return true;
    }
};