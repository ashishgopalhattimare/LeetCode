// https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/
// Medium
// List + Unique Character
// Weekly Contest

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(S.length() < K) return 0;
        
        vector<int>freq(26, 0);
        
        int count = 0, start = 0;
        for(int i = 0; i < S.length(); i++) {
            
            freq[S[i]-'a']++;
            if(freq[S[i]-'a'] == 1) { // single character
                if(K == (i-start+1)) {// If length met, count++ and remove first character from this string
                    freq[S[start++]-'a']--;
                    count++;
                }
            }
            else {
                while(S[start] != S[i]) { // duplicate found, remove until there is only character of curretn duplicate
                    freq[S[start++]-'a']--;
                }
                freq[S[start++]-'a']--;
            }
        }
        
        return count;
    }
};
