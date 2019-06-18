// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Medium

class Solution {
public:
    int minAddToMakeValid(string S) {
        
        stack<char>st;
        int addBracket = 0;
        
        for(char c : S) {
            switch(c) {
                case '(':   st.push('('); break;
                case ')':   if(!st.empty()) st.pop();
                            else addBracket++; // if no '(' for ')', increment bracket
            }
        }
        return addBracket + st.size(); // add if any open bracket left
    }
};
