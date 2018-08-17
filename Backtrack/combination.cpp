class Solution {
public:
    
    stack<int>temp;
    
    void combination(int index, int n, int k, vector<vector<int> >& result, stack<int>& st, int count)
    {
        if(k == count) {
            while(!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            vector<int>v;
            while(!temp.empty()) {
                v.push_back(temp.top());
                st.push(temp.top());
                temp.pop();
            }
            result.push_back(v);
            
            return;
        }
        for(int i = index; i <= n; i++) {
            st.push(i);
            combination(i+1, n, k, result, st, count+1);
            st.pop();
        }
        
        return;
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        
        stack<int>st;
        combination(1, n, k, result, st, 0);
        
        return result;
    }
};
