// https://leetcode.com/problems/find-and-replace-pattern/
// Hint : Use 2 Map : X - > L -> X

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<char>map1(26, '*');
        vector<char>map2(26, '*');
        char m, p;
        
        vector<string>result;
        for(string x : words) {
            if(x.length() == pattern.length()) {
                bool pos = true;
                for(int i = 0; i < x.length(); i++) {
                    p = pattern[i]; m = x[i];
                    if(map1[m-'a'] == '*') map1[m-'a'] = p; // if X -> L is not set to any
                    if(map2[p-'a'] == '*') map2[p-'a'] = m; // if L -> X is not set to any
                    
                    if(map1[m-'a'] != p || map2[p-'a'] != m) {
                        pos = false;
                        break;
                    }
                }
                
                if(pos)  result.push_back(x);
                for(char& c : map2) c = '*';
                for(char& c : map1) c = '*';
            }
        }
        return result;
    }
};

// a -> y
// o -> a
    
