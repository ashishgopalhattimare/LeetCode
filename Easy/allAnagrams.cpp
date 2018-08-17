/**
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 * 
 * another solution : sliding window problem (O(n)) using incoming and outgoing char
 * in the window
**/

class Solution {
public:
    
    void reset(vector<int>& v)
    {
        for(int i = 0; i < v.size(); i++) v[i] = 0;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>hashp(26);
        vector<int>hashs(26);
        
        reset(hashp);
        for(int i = 0; i < p.length(); i++) { // pattern anagram check
            hashp[p[i]-'a']++;
        }
        
        vector<int> result;
        
        int limit = s.length() - p.length();
        for(int i = 0; i <= limit; i++) {
            reset(hashs);
            for(int j = i; j < i + p.length(); j++) {
                hashs[s[j]-'a']++;
            }
            
            if(equal(hashs.begin(), hashs.end(), hashp.begin())) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};