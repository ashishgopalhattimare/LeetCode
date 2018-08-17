// https://leetcode.com/problems/word-pattern/description/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, string> hash1;
        unordered_map<string, char> hash2;
        
        int pIndex = 0;
        string str = "";
        for(int i = 0; i <= s.length(); i++) {
            if(s[i] == ' ' || s[i] == '\0') {
                
		// if both the locations are not taken
                if(hash1.find(pattern[pIndex]) == hash1.end() && hash2.find(str) == hash2.end()) {
                    hash1[pattern[pIndex]] = str;
                    hash2[str] = pattern[pIndex];
                }
		// either one is taken
                else {
			// check if the taken spot is corresponding or not
                    if(hash1[pattern[pIndex]] != str || hash2[str] != pattern[pIndex]) return false;
                }
                
                pIndex++;
                str = "";
                continue;
            }
            str.push_back(s[i]);
        }
        
        return (pIndex == pattern.length());
    }
};
