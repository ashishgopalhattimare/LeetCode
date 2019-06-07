// https://leetcode.com/problems/longest-palindrome/
// Easy

#define ASCII 135

class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int>freq(ASCII, 0);
        for(int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }
        
        int result = 0;
        for(int i = 0; i < ASCII; i++) {
            if(freq[i] > 1) {
                result += (freq[i] >> 1)*2;
                freq[i] = freq[i]%2;
            }
        }
        for(int i = 0; i < ASCII; i++) {
            if(freq[i]) return result + 1;
        }
        
        return result;
    }
};
