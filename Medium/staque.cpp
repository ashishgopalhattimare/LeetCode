#include<bits/stdc++.h>
using namespace std;

#define LL long long int

LL algorithm(vector<LL>& arr, int n, int k)
{
    vector<LL>sufix(n+1);

    // Compute Sufix Array
    sufix[n-1] = arr[n-1]; sufix[n] = 0;
    for(int i = n-2; i >= 0; i--) sufix[i] = arr[i] + sufix[i+1];
    
    LL totalSum = 0, prefixSum = 0;

    for(int i = 1; i <= k; i++) {
        prefixSum += arr[i-1];
        totalSum = max(totalSum, prefixSum + sufix[n-k+i]);
    }

    return totalSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ifstream infile; infile.open("input.txt");
    
    //Code Here
    int N, K;
    cin >> N >> K;

    vector<LL>arr(N+1, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << algorithm(arr, N, K) << '\n';

    return 0;
}