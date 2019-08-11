// https://www.geeksforgeeks.org/maximum-number-segments-lengths-b-c/

#include <bits/stdc++.h>

using namespace std;

int algorithm(int n, int len, ...)
{
    va_list nums; // var_arg documentation
    va_start(nums, len); // start the va_arg arr

    set<int>set;
    int x;
    for(int i = 0; i < len; i++) {
        x = va_arg(nums, int);
        set.insert(x);
    }

    vector<int>arr;
    for(auto itr = set.begin(); itr != set.end(); itr++) {
        arr.push_back(*itr);
    }

    vector<int>dp(n+1, 0);

    for(int i = 0; i < arr.size(); i++) {
        for(int j = 1; j <= n; j++) {
            if(j == arr[i]) dp[j] = max(dp[j], 1);
            else if(j > arr[i]) {
                if(dp[j-arr[i]] == 0) continue;
                else {
                    dp[j] = max(dp[j], dp[j-arr[i]]+1);
                }
            }
        }

        if(dp[n] != 0) break; // once found, break
    }
    
    return dp[n];
}

int main()
{
    cout << algorithm(7, 3/*Size of the array */,2,3,5) << endl;

    return 0;
}