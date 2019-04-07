// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0

#include <bits/stdc++.h> 

using namespace std;

int main(int argc, char* argv[])
{
    int t;
    int n;
    
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int>arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        
        int maxim = 1;
        int count = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i-1] == arr[i]-1) {
                maxim = max(maxim, ++count);
            }
            else count = 1;
        }
        
        cout << maxim << endl;
    }

    return 0;
}
