// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    
    void countPalinLen(const string str, int l, int r, int *maxLen, int *gl, int *gr) {
        
        while(l >= 0 &&  r < str.length()) {
            if(str[l] == str[r]) {
                
                if(*maxLen < r - l) {
                    *maxLen = r - l;
                    *gl = l;
                    *gr = r;
                }
                l--; r++;
            }
            else break;
        }
    }
    
    string longestPalindrome(string str) {
        
        if(str.length() == 0) return "";
        
        int l, r, gl = 0, gr = 0;
        
        int len, lenMax = INT_MIN;
        for(int i = 0; i < str.length(); i++) {
            
            // even string
            countPalinLen(str, i, i+1, &lenMax, &gl, &gr);
            countPalinLen(str, i, i, &lenMax, &gl, &gr);
        }
        
        string result = "";
        while(gl <= gr) {
            result.push_back(str[gl++]);
        }
        
        return result;
    }
};