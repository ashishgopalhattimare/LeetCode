// https://www.geeksforgeeks.org/number-nges-right/
#include <bits/stdc++.h>

using namespace std;

vector<int> preCompute(vector<int>& nums)
{
    vector<int>dp(nums.size(), 0);
    stack<int>st;

    for(int i = nums.size()-1; i >= 0; i--) {
        while(!st.empty() && nums[i] >= nums[st.top()]) {
            dp[st.top()] = st.size()-1;
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()) {
        dp[st.top()] = st.size()-1;
        st.pop();
    }

    return dp;
}

int main()
{
    vector<int> nums = {3, 4, 2, 2, 3, 7, 5, 5, 8, 10, 6};
    
    vector<int>DP = preCompute(nums);

    for(int x : DP) printf("%d ", x);
    printf("\n");

    return 0;
}