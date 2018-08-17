class Solution {
public:
    
    stack<int>temp;
    void combinationSum(int index, int sum, int k, int n, stack<int>& st, int count, vector<vector<int> >& result)
    {
        if(sum > n && k > count) {return; }
        
        if(sum == n && k == count)
        {
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
        
        for(int i = index; i < 10; i++) {
            st.push(i);
            combinationSum(i+1, sum + i, k, n, st, count+1, result);
            st.pop();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int> > result;
        
        stack<int> st;
        combinationSum(1, 0, k, n, st, 0, result);
        
        return result;
    }
};
