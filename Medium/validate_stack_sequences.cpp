// https://leetcode.com/contest/weekly-contest-112/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>st;
        
        int i = 0, j = 0;
        while(i < pushed.size() ) {
            if(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i++]);
            }
        }
        
        while(j < popped.size() && !st.empty()) {
            if(st.top() != popped[j++]) {
                return false;
            }
            st.pop();
        }
        
        return true;
    }
};
