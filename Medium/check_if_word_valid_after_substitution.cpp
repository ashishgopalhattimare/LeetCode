// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {
public:
    
    bool isValid(string S) {
        int pos;
        while(S.length() && (pos = S.find("abc")) >= 0) {
            S.erase(pos, 3);
        }
        
        return S.length() == 0;
    }
};
