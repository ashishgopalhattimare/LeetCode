// https://www.hackerearth.com/challenges/competitive/march-circuits-19/algorithm/wet-clothes-625348cf/

#include <bits/stdc++.h>
using namespace std;

int algorithm(vector<int>& t, vector<int>& a)
{
    int duration;
    sort(a.begin(), a.end());
    
    vector<int>picks;
    
    int low = 0, pick;
    for(int i = 1; i < t.size(); i++) {
        duration = t[i] - t[i-1];
        
        pick = 0;
        while(low < a.size() && a[low] <= duration) {
            pick++; low++;
        }
        if(pick) picks.push_back(pick);
    }
    
    int totalPicks = 0;
    for(int i = 0; i < picks.size(); i++) totalPicks += picks[i];
    
    return totalPicks;
}

int main()
{
    int n, m, g;
    cin >> n >> m >> g;
    
    vector<int>t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<int>a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    cout << algorithm(t, a) << endl;
    
    return 0;
}

/**
4 8 2

3   5   8   12
  2   3   4

1 1 1 1 1 1 3 4

**/
