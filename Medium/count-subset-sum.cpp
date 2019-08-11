#include <bits/stdc++.h>
using namespace std;

int countSets = 0;

void printSubsetSum(vector<int>& arr, int i, int sum, /*vector<int>& p,*/
vector<vector<bool>>& DP)
{
    if(i == 1 && sum != 0 && DP[1][sum]) {
        // p.push_back(arr[i]);
        countSets++;

        // for(int x : p) cout << x << " ";
        // printf("\n");

        return;
    }
    if(i == 1 && sum == 0) {
        // for(int x : p) cout << x << " ";
        // printf("\n");
        countSets++;
        
        return;
    }

    if(DP[i-1][sum]) {
        // vector<int> b = p;
        printSubsetSum(arr, i-1, sum, /*b,*/ DP);
    }

    if( sum >= arr[i] && DP[i-1][sum-arr[i]]) {
        // p.push_back(arr[i]);
        printSubsetSum(arr, i-1, sum-arr[i], /*p,*/ DP);
    }
}

int GoldenSubsetSum(int n)
{
    int sum = 0;
    vector<int>arr(n+1, 0);
    for(int i = 1; i <= n; i++) {
        sum += i;
        arr[i] = i;
    }

    if(sum % 2) return 0;

    sum /= 2;
    vector<vector<bool>>DP(n+1, vector<bool>(sum+1, false));
    for(int i = 0; i <= n; i++) {
        DP[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(j >= i) {
                DP[i][j] = DP[i-1][j-i] || DP[i-1][j];
            }
            else {
                DP[i][j] = DP[i-1][j];
            }
        } 
    }

    printSubsetSum(arr, n, sum, /*print,*/ DP);

    return countSets;
}

long long GetNumberOfSubsets(int n) {
    vector<int>numbers(n);
    
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        numbers[i-1] = i;
        sum += i;
    }

    if(sum % 2) return 0;

    sum /= 2;
    vector<long long>DP(sum+1, 0);
    DP[0] = 1;

    for(int i = 0; i < numbers.size(); i++) {
        for(int j = sum; j >= numbers[i]; j--) {
            DP[j] += DP[j - numbers[i]];
        }

        for(int x : DP) cout << x << " ";
        printf("\n");
    }

    return DP[sum];
}

int main()
{
    int n;
    cin >> n;

    cout << GetNumberOfSubsets(n)/2 << endl;
    cout << GoldenSubsetSum(n)/2 << endl;

    return 0;
}