// https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

// Using sliding window approach

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
        
        if(p.length() > s.length()) return result;
        
        int i = 0;
        for( ; i < p.length(); i++) { hashs[s[i]-'a']++; }
        
        int rem = 0;
        if(equal(hashs.begin(), hashs.end(), hashp.begin())) {
            result.push_back(rem);
        }
        
        for( ; i < s.length(); i++) {
            hashs[s[rem]-'a']--;
            hashs[s[i]-'a']++;
            
            rem++;
            if(equal(hashs.begin(), hashs.end(), hashp.begin())) {
                result.push_back(rem);
            }
        }
        
        return result;
    }
};