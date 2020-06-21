// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/grandmaster/
// Medium, Stacks

#include <bits/stdc++.h>
using namespace std;

#define LL long long int

// 1 2 2 2 3 2 2 1 given array
// 1 2 1 1 5 1 1 1 lessLHS (elements less than current index on LHS, excluding itself)
// 1 3 2 1 4 3 2 1 lessRHS (elements less than current index on RHS, including itself)

int bruteForce(vector<int>& arr, int x)
{
    int count = 0;
    int maxim;
    for(int i = 0; i < arr.size(); i++) {
        maxim = INT_MIN;
        for(int j = i; j < arr.size(); j++) {
            maxim = max(maxim, arr[j]);
            if(x == maxim) count++;
        }
    }
    return count;
}

void algorithm(vector<int>& arr, int start, int end, int fc, vector<LL>& arrange, bool include)
{
    stack<vector<int>>st;

    for(int i = start; i != end; i += fc) {

        vector<int>curr = {i, arr[i], 0};
        
        // if excluding the current element : while(!st.empty() && st.top().at(1) <  arr[i]);
        // if including the current element : while(!st.empty() && st.top().at(1) <= arr[i]);

        while(!st.empty() && st.top().at(1) <= arr[i] - include) {
            vector<int>temp = st.top();
            st.pop();
 
            arrange[temp[0]] += (temp[2]+1);
            curr[2] += (temp[2]+1);
        }
        st.push(curr);
    }

    while(!st.empty()) {
        vector<int>temp = st.top();
        st.pop();
        arrange[temp[0]] += (temp[2]+1);
    }
}

int main()
{
    map<int, long long int>mapi;

    int n, data;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<LL>lessLHS(n, 0), lessRHS(n, 0);

    algorithm(arr, 0, n, 1, lessLHS, false);
    algorithm(arr, n-1, -1, -1, lessRHS, true);

    for(int i = 0; i < n; i++) mapi[arr[i]] += (lessLHS[i] * lessRHS[i]);
    
    // for(int i = 0; i < n; i++) printf("%d ", lessLHS[i]); printf("\n");
    // for(int i = 0; i < n; i++) printf("%d ", lessRHS[i]); printf("\n");
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> data;
        cout << mapi[data] << '\n';
    }

    return 0;
}