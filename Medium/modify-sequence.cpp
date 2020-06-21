// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/modify-sequence/
// Ad-Hoc, Array-1D

#include <bits/stdc++.h>
using namespace std;

bool allZero(vector<int>& arr) {
    for(int x : arr) { if(x) return false;
    }
    return true;
}
 
int main() {
    
    int n;
 
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int minim;
 
    int low = 0, high = 1;
    while(low < n && high < n && high == low + 1) {

        minim = min(arr[low], arr[high]);

        arr[high] -= minim;
        arr[low] -= minim;

        if(arr[high] == 0) high++;
        while(low < n && (arr[low] == 0 || high == low)) low++;

        if(high < low) swap(high, low);
    }
 
    if(allZero(arr)) cout << "YES" << endl;
    else cout << "NO" << endl;
 
    return 0;
}