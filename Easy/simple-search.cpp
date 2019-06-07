// https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/simple-search-4/
// pair Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<pair<long long int,int>>& arr, int s, int e, long long int k) {
    if(s > e) return -1;
    
    if(s == e || e == s+1) {
        if(arr[s].first == k) return arr[s].second;
        if(arr[e].first == k) return arr[e].second;
        
        return -1;
    }
    
    int mid = (s+e)/2;
    if(arr[mid].first == k) return arr[mid].second;
    
    if(k < arr[mid].first) return binarySearch(arr, s, mid, k);
    return binarySearch(arr, mid, e, k);
}

int main()
{
    long long int d;
    int n;
    
    cin >> n;
    vector<pair<long long int,int>>arr(n);
    for(int i = 0; i < n; i++) {
        cin >> d;
        arr[i] = make_pair(d, i);
    }
    sort(arr.begin(), arr.end(), [](pair<long long int,int>& a, pair<long long int,int>& b){
        return a.first < b.first;
    });
    
    long long int k;
    cin >> k;
    cout << binarySearch(arr, 0, arr.size()-1, k) << endl;
    return 0;
}
