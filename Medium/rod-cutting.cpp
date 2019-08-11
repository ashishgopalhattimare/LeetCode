#include <bits/stdc++.h>

using namespace std;

int rodCutting(vector<int>& input)
{
    int rodLength = input.size();

    vector<int>dp(rodLength+1, 0);

    for(int i = 0; i < input.size(); i++) {
        
        for(int j = i+1; j <= rodLength; j++) {
            dp[j] = max(dp[j], input[i] + dp[j-(i+1)]);
        }
    }

    return dp[rodLength];
}

int main()
{
    vector<int> input = {3,5,8,9,10,17,17,20};

    cout << "Maximum obtainable value is : " << rodCutting(input) << endl;

    return 0;
}