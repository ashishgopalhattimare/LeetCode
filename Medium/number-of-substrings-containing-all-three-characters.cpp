// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Medium

class Solution { // abcab
public:
    
    int numberOfSubstrings(string s) {
        
        unordered_map<char, int>freq;
        freq['a'] = 0;
        freq['b'] = 0;
        freq['c'] = 0;
        
        int start = -1, distinct = 0;
        
        for(start = 0; start < s.length(); start++) {
            if(freq.find(s[start]) != freq.end()) {
                break;
            }
        }
        
        int result = 0;
        
        for(int i = start; i < s.length(); i++) {
            if(freq.find(s[i]) != freq.end()) {
                
                if(freq[s[i]] == 0) distinct++;
                freq[s[i]]++;
                
                while(distinct == 3) {
                    
                    result += (s.length()-i-1+1);
                    
                    if(freq[s[start]] == 1) distinct--;
                    freq[s[start++]]--;
                }
            }
        }
        
        return result;
    }
    
    // aaabbc
       // ^    ^
};