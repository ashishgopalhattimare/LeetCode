// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    void reverseWords(string &s) {
        
        string str = "";
        stack<string>st;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ' && str.length() > 0) {
                st.push(str);
                str = "";
            }
            else if(s[i] == ' ') continue;
            else {
                str.push_back(s[i]);
            }
        }
        
        if(str.length() > 0) {
            st.push(str);
        }
        
        string result = "";
        if(st.empty()) {
            s = result;
            return;
        }
        
        result.append(st.top());
        st.pop();
        
        while(!st.empty()) {
            result.push_back(' ');
            result.append(st.top());
            
            st.pop();
        }
        
        s = result;
        return;
    }
};