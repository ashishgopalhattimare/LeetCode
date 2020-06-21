// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/circular-list-8e1319c9/
// Easy, Stack, Prime

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005

vector<vector<int>> queue_and_stack (vector<int>& A) {
    
    vector<bool>prime(MAX, true);
    for(int i = 2; i*i < MAX; i++) {
        if(prime[i]) {
            for(int j = i*i; j < MAX; j+=i) {
                prime[j] = false;
            }
        }
    }

    queue<int>qq; stack<int>st;

    for(int x : A) {
        if(prime[x]) qq.push(x);
        else st.push(x);
    }

    vector<int>qarr(qq.size()), sarr(st.size());
    for(int i = 0; i < qarr.size(); i++) {
        qarr[i] = qq.front();
        qq.pop();
    }
    for(int i = 0; i < sarr.size(); i++) {
        sarr[i] = st.top();
        st.pop();
    }

    return {qarr, sarr};
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
    	cin >> A[i_A];
    }

    vector<vector<int> > out_;
    out_ = queue_and_stack(A);
    for(int i_out_=0; i_out_<out_.size(); i_out_++)
    {
    	cout << out_[i_out_][0];
    	for(int j_out_=1; j_out_<out_[i_out_].size(); j_out_++)
    	{
    		cout << " " << out_[i_out_][j_out_];
    	}
    	cout << "\n";
    }
}