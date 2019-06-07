/** CODE **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int>arr(n);
    set<int>distinct;
    
    // Count the number of distinct elements in the input array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        distinct.insert(arr[i]); // distinct parent set
    }
    
    unordered_map<int,int>map; // store the frequency of each element in the subarray
    unordered_set<int>set; // subarray distinct elements
    
    long long int result = 0;
    int end = 0;
    for(int start = 0; start < n; start++) { // start of each subarray
        
        // If end index is valid or number of distinct elements in subarray set
        // is not equal to distinct parent set
        while(end < n && set.size() < distinct.size()) {
            map[arr[end]]++; // increment frequency
            set.insert(arr[end]); // add to subarray set
        
            end++; // increment end index
        }
        
        // if distinct element count is same, this subarray is valid and
        // also subarray with next (n-end) elements <>
        if(set.size() == distinct.size()) {
            result += (n-end+1);
        }
        
        // decrement frequency of start element by 1
        map[arr[start]]--;
        // if the frequency of start element is 0, remove from subarray set
        if(map[arr[start]] == 0) {
            set.erase(arr[start]);
        }
    }
    
    // output the result
    cout << result << endl;
    return 0;
}
