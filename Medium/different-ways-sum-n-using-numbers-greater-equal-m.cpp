// https://www.geeksforgeeks.org/different-ways-sum-n-using-numbers-greater-equal-m/
// Medium

#include <bits/stdc++.h>

using namespace std;

int algorithm(int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int j = 1; j <= n; j++) {
        if(j % m == 0) dp[m][j] = 1;
    }

    // for(int i = m; i <= n; i++) {
    //     printf("%d : ", i);
    //     for(int j = 1; j<= n; j++) {
    //         printf("%2d ", dp[i][j]);
    //     } printf("\n");
    // } printf("\n");

    bool pModulo;
    for(int i = m+1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j < i) dp[i][j] = dp[i-1][j];
            else {
                pModulo = (j % i == 0); // extra if j is multiple of i
                dp[i][j] = dp[i-1][j] + dp[i-1][j-i] + pModulo;
            }
        }
    }

    // for(int i = m; i <= n; i++) {
    //     printf("%d : ", i);
    //     for(int j = 1; j<= n; j++) {
    //         printf("%2d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    return dp[n][n];
}

int main()
{
    int m = 1;
    int n = 4;

    cout << algorithm(n, m) << endl;

    return 0;
}