// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        if(S.length() == 0 && T.length() == 0) return true;
        
        deque<char>dq;
        
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == '#') {
                if(!dq.empty()) dq.pop_back();
            }
            else dq.push_back(S[i]);
        }
        
        string ss = "";
        while(!dq.empty()) {
            ss.push_back(dq.front());
            dq.pop_front();
        }
        
        for(int i = 0; i < T.length(); i++) {
            if(T[i] == '#') {
                if(!dq.empty()) dq.pop_back();
            }
            else dq.push_back(T[i]);
        }
        
        string tt = "";
        while(!dq.empty()) {
            tt.push_back(dq.front());
            dq.pop_front();
        }
        
        return ss == tt;
    }
};