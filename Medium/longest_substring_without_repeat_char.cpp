// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    
    int hash[256];
    
    int lengthOfLongestSubstring(string s) {
        
        for(int i = 0; i < 256; i++) {
            hash[i] = 0;
        }
        
        int maxLength = 0;
        
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            hash[s[i]]++;
            
            if(hash[s[i]] == 2) {
                while(s[start] != s[i]) {
                    hash[s[start++]]--;
                }
                hash[s[start++]]--;
            }
            else {
                maxLength = max(maxLength, i - start + 1);
            }
        }
        
        return maxLength;
    }
};