// https://leetcode.com/problems/number-of-segments-in-a-string/description/

class Solution {
public:
    int countSegments(string s) {
        
        s.erase(s.find_last_not_of(" \n\r\t")+1);
        
        // epmty string
        if(s.length() == 0) return 0;
        
        // string length is > 0
        int count = 0;
        char prev = ' ';
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && prev != s[i]) {
                count++;
            }
            prev = s[i];
        }
        return count + 1;
    }
};