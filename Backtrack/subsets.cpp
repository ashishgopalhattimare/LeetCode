
stack<int>t;

void backtracking(int index, vector<int>&a, stack<int>s, vector<vector<int> >&V)
{
    
    for(int i = index; i < a.size(); i++) {
        s.push(a[i]);
        
        ////////////////////////////////////////////////////////
        vector<int> v;
        while(!s.empty()) {
            ::t.push(s.top());
            s.pop();
        }
        while(!::t.empty()) {
            v.push_back(t.top());
            s.push(t.top());
            t.pop();
        }
        V.push_back(v);
        /////////////////////////////////////////////////////////
        
        backtracking(i+1, a, s, V);
        s.pop();
    }
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &A)
{
    vector<vector<int> > V;
    
    vector<int>v;
    V.push_back(v);
    
    stack<int>st;
    backtracking(0, A, st, V);
    
    return V;
}
