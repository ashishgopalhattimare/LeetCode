// https://leetcode.com/articles/verifying-an-alien-dictionary/
// Mock Test : problem 1

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int>hash;
        for(int i = 0; i < order.length(); i++) {
            hash[order[i]] = i;
        }
        
        if(words.size() <= 1) return true;
        
        bool smaller;
        for(int i = 1; i < words.size(); i++) {
            string prev = words[i-1];
            string curr = words[i];
            
            smaller = false;
            
            int i1 = 0, i2 = 0;
            while(i1 < prev.length() && i2 < curr.length()) {
                if(hash[prev[i1]] < hash[curr[i2]]) {
                    smaller = true;
                    break;
                }
                else if(hash[prev[i1]] > hash[curr[i2]]) {
                    return false;
                }
                
                i1++; i2++;
            }
            if(!smaller && i1 < prev.length()) return false;
        }
        return true;
    }
};
