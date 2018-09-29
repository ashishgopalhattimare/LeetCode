// https://leetcode.com/problems/count-binary-substrings/hints/

class Solution {
public:
    
    int countBinary(string& str, char cc)
    {
        int count = 0;
        int c1, c2;
        
        c1 = c2 = 0;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == cc) {
                c2++;
            } else {
                count += min(c1, c2);
                c1 = c2;
                c2 = 1;
                
                if(cc == '1') cc = '0';
                else cc = '1';
            }
        }
        count += min(c1,c2);
        
        return count;
    }
    
    int countBinarySubstrings(string s) {
        
        return countBinary(s, s[0]);
    }
};