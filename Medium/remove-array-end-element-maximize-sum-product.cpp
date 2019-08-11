// https://www.geeksforgeeks.org/remove-array-end-element-maximize-sum-product/
// Medium (Good Question to move from 2^n to n^2)

#include <bits/stdc++.h>

using namespace std::chrono;
using namespace std;

int brute(vector<int>& arr, int low, int high, int n,
vector<vector<int>>& dp)
{
    if(low == high) return arr[low]*n;

    if(dp[low][high] != INT_MIN) return dp[low][high];

    int l = arr[low] * n + brute(arr, low+1, high, n+1, dp);
    int r = arr[high] * n + brute(arr, low, high-1, n+1, dp);

    // return max(l, r);

    dp[low][high] = max(l, r);
    return dp[low][high];
}

int algorithm(vector<int>& input)
{
    vector<vector<int>>dp(input.size(), vector<int>(input.size(),INT_MIN));
    
    auto start = high_resolution_clock::now();// START TIME

    int result = brute(input,0, input.size()-1, 1, dp);

    auto stop = high_resolution_clock::now(); // END TIME

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken : " << duration.count() << " ms" << endl;

    return result;
}

int main()
{
    vector<int> input = {1,3,1,5,2,4,5,1,12,532,3,12,12,12,1,12,1,1,1,1,1,1,12,3,23,2,1,23,2,1};

    cout << algorithm(input) << endl;

    return 0;
}