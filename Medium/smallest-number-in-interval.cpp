// https://www.careercup.com/question?id=5565570867003392

// 

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k, start, end;
    int minim, maxim;
    
    vector<pair<int,int>>arr;
    cin >> n >> k;
    while(n--) {
        cin >> start >> end;
        
        minim = min(minim, start);
        maxim = max(maxim, end);
        
        arr.push_back(make_pair(start, end));
    }
    
    vector<int>frequency(maxim+2, 0);
    for(pair<int,int>& x : arr) {
        frequency[x.first]++;
        frequency[x.second+1]--;
    }
    
    int sum = 0;
    int result = -1;
    for(int i = minim; i <= maxim; i++) {
        sum += frequency[i];
        if(k <= sum) {
            result = i;
            break;
        }
        k-= sum;
    }
    
    cout << result << endl;
    
    return 0;
}
