// https://leetcode.com/problems/longest-uncommon-subsequence-ii/

class Solution {
public:
    
    int max(int x, int y) {
        return (x > y) ? x : y;
    }
    
    // whether a is a subsequence of b or not
    bool notSubsequence(string& a, string& b) {
        if(a.length() > b.length()) return true;
        
        int count = a.length();
        
        int i = 0;
        for(int j = 0; j < b.length() && count; j++) {
            if(a[i] == b[j]) {
                count--;
                i++;
            }
        }
        
        return (count != 0); // if the count is not zero, then a is not a subsequence of b
    }
    
    int findLUSlength(vector<string>& strs) {
        
        int maxim = -1;
        bool possible;
        for(int i = 0; i < strs.size(); i++) {
            string a = strs[i];
            
            possible = true;
            for(int j = 0; j < strs.size() && possible; j++) {
                if(i == j) continue;
                
                // if the word is a subsequence of any other word, ignore it
                if(!notSubsequence(a, strs[j])) {
                    possible = false;
                }
            }
            
            if(possible) {
                maxim = max(maxim, a.length());
            }
        }
        return maxim;
    }
};
