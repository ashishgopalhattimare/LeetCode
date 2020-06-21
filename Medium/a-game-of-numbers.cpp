// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
// Easy, Stack

#include<bits/stdc++.h>
using namespace std;

vector<int> gameNumbers(vector<int>& arr)
{
    vector<int>result(arr.size(), -1);
    int n = arr.size();

    vector<int>large(n, -1), small(n, -1);

    stack<vector<int>>st;

    for(int i = n-1; i >= 0; --i) {
        while(!st.empty() && arr[i] >= st.top().at(1)) {
            st.pop();
        }
        if(!st.empty()) large[i] = st.top().at(0);
        
        st.push({i, arr[i]});
    }

    while(!st.empty()) st.pop();

    for(int i = n-1; i >= 0; --i) {
        while(!st.empty() && arr[i] <= st.top().at(1)) {
            st.pop();
        }
        if(!st.empty()) small[i] = st.top().at(0);

        st.push({i, arr[i]});
    }

    for(int i = 0; i < n; i++) {
        if(large[i] != -1 && small[large[i]] != -1) {
            result[i] = arr[small[large[i]]];
        }
    }
    return result;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream infile;
    infile.open("input.txt");

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> result = gameNumbers(arr);
    for(int x : result) printf("%d ", x);
    
    return 0;
}