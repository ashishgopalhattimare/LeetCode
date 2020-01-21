// https://leetcode.com/problems/jump-game-iii/
// Medium

class Solution {
public:
    
    bool inrange(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        stack<int>st;
        st.push(start);
        
        int n = arr.size();
        
        while(!st.empty()) {
            start = st.top();
            st.pop();
            
            if(arr[start] < 0) continue;
            
            if(arr[start] == 0) return true;
            
            if(inrange(start-arr[start], n) && arr[start-arr[start]] >= 0) {
                st.push(start-arr[start]);
            }
            if(inrange(start+arr[start], n) && arr[start+arr[start]] >= 0) {
                st.push(start+arr[start]);
            }
            
            arr[start] = -arr[start];
        }
        
        return false;
    }
};