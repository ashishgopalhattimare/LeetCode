// https://leetcode.com/problems/baseball-game/
// Easy

class Solution {
public:
    
    stack<int>st;
    int popData() {
        int temp = 0;
        
        if(!st.empty()) { temp = st.top(); st.pop(); }
        return temp;
    }
    
    int calPoints(vector<string>& ops) {
        
        int x, y;
        for(string s : ops) {
            
            if(s == "+") {
                x = popData();
                y = popData();
                
                st.push(y); st.push(x); st.push(x+y);
            }
            else if(s == "C") popData();
            else if(s == "D") {
                if(!st.empty()){
                    x = popData();
                    st.push(x); st.push(2*x);
                }
            }
            else {
                st.push(stoi(s));
            }
            
        }
        
        int total = 0;
        while(!st.empty()) total += popData();
        
        return total;
    }
};