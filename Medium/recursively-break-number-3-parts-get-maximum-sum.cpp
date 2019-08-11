// https://www.geeksforgeeks.org/recursively-break-number-3-parts-get-maximum-sum/
// Good Use of Map
// Memoised

#include <bits/stdc++.h>

using namespace std;

static unordered_map<int,int>mapi;

int algorithm(int n) {
    
    if(n == 0 || n == 1) return n;

    if(mapi.find(n) != mapi.end()) {
        return mapi[n];
    }

    mapi[n] = max(algorithm(n/2) + algorithm(n/3) + algorithm(n/4), n);

    return mapi[n];
}

int main()
{
    cout << algorithm(12) << endl;
    cout << algorithm(24) << endl;
    cout << algorithm(23) << endl;

    return 0;
}