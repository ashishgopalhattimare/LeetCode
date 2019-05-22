// https://leetcode.com/contest/weekly-contest-131/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        
        stack<char>st;
        string result = "";
        
        for(int i = 0; i < S.length(); i++) {
            
            switch(S[i]) {
                case '(':   
                    if(!st.empty()) {
                        result.push_back(S[i]);
                    }
                    st.push('(');
                    break;
                
                case ')':
                    st.pop();
                    if(!st.empty()) {
                        result.push_back(S[i]);
                    }
            }
        }
        
        return result;
    }
};
