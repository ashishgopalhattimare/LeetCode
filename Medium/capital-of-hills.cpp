// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/capital-of-hills/
// Medium

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = n-1;

    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = n-1; i >= 0; --i) {
        while(!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        if(!st.empty()) result++;
        st.push(arr[i]);
    }
    return 0;
}