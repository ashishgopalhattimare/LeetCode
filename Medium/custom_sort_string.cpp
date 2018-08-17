// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    
    int hash[26];
    string customSortString(string S, string T) {
        
        for(int i = 0; i < 26; i++) {
            hash[i] = 0;
        }
        
        for(int i = 0; i < T.length(); i++) {
            hash[T[i]-'a']++;
        }
        
        string result;
        for(int i = 0; i < S.length(); i++) {
            while(hash[S[i]-'a']) {
                result.push_back(S[i]);
                hash[S[i]-'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            while(hash[i]) {
                result.push_back('a'+i);
                hash[i]--;
            }
        }
        
        return result;
    }
};