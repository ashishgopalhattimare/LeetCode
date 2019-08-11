// https://www.geeksforgeeks.org/number-n-digits-non-decreasing-integers/

#include <bits/stdc++.h>

using namespace std;

void algorithm(int n)
{
    vector<vector<int>>dp(n+1, vector<int>(10,1));

    for(int i = 1; i <= n; i++) { // number of digits
        for(int j = 8; j >= 0; j--) {
            dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }

    cout << "\nResult : " << dp[n][0] << endl;
}

int main()
{
    int n = 3;

    algorithm(n);

    return 0;
}