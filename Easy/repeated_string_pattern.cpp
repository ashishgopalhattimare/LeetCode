// https://leetcode.com/problems/repeated-substring-pattern/description/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int len = s.length();
        string repeat = "";
        for(int i = 0; i < len/2; i++) {
            
            repeat.push_back(s[i]);
            
            if(len % (i+1) == 0) { // modification for division not by 0
                string temp = repeat;
                while(temp.length() < s.length()) {
                    temp.append(repeat);
                }
                
                if(temp == s) return true;
            }
        }
        
        return false;
    }
};