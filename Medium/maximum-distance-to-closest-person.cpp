// https://leetcode.com/problems/maximize-distance-to-closest-person/
// Easy

class Solution {
public:
    
    void compute(vector<int>& seats, vector<int>& distance, int s, int e, int factor)
    {
        stack<int>st;
        int index;
        for(int i = s; i != e; i+=factor) {
            if(seats[i] == 0) st.push(i);
            else {
                index = 1;
                while(!st.empty()) {
                    distance[st.top()] = index++;
                    st.pop();
                }
            }
        }
        while(!st.empty()) {
            distance[st.top()] = st.size();
            st.pop();
        }
    }
    
    int maxDistToClosest(vector<int>& seats) {
        
        vector<int>lr(seats.size(), 0);
        vector<int>rl(seats.size(), 0);
        
        compute(seats, rl, seats.size()-1, -1, -1);
        compute(seats, lr, 0, seats.size(), 1);
        
        int closest = 0;
        for(int i = 0; i < lr.size(); i++) {
            if(closest < min(lr[i], rl[i])){
                closest = min(lr[i], rl[i]);
            }
        }
        
        return closest;
    }
};
