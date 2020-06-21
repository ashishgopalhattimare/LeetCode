// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/description/
// Easy, Stack

#include <bits/stdc++.h>
using namespace std;

int littleShino(vector<int>& nums)
{
    int count = 0;

    stack<int>st;
    for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[i] > st.top()) {
            st.pop();
            count++;
        }
        if(!st.empty()) count++;
        st.push(nums[i]);
    }
    return count;
}

int main() {
    
    int N, data;
    cin >> N;
    
    vector<int>arr(N);
    for(int i = 0; i < N; i++) 
        cin >> arr[i];

    cout << littleShino(arr) << endl;
    
    return 0;
}