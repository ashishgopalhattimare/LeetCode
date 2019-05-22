// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/deleting-numbers-efb41d85/

#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    int k, data;
    
    cin >> n >> k;
    
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> data;
        
        arr[i] = data;
    }
    
    int mid = (n-k+1)/2;
    int left = mid-1;
    int right = n-k-mid;
    
    int maxim = INT_MIN;
    for(int i = left; i +right < n; i++) {
        maxim = max(maxim, arr[i]);
    }
    cout << maxim << endl;
    
    return 0;
}
