class Solution {
public:
    
    stack<int>temp;
    void combinationSum(int index, int sum, vector<int>& candidates, int target, vector<vector<int> >& result, stack<int>& st)
    {
        if(sum > target) return;
        
        if(sum == target) {
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
        for(int i = index; i < candidates.size(); i++) {
            st.push(candidates[i]);
            combinationSum(i, sum + candidates[i], candidates, target, result, st);
            st.pop();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        stack<int> st;
        vector<vector<int> > result;
        
        combinationSum(0, 0, candidates, target, result, st);
        
        return result;
    }
};
