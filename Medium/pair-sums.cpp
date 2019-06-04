// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/
// Easy, HashTable

#include <bits/stdc++.h>
using namespace std;

string algorithm(vector<int>& nums, int k)
{
    unordered_map<int,int>map;
    for(int x : nums) {
        map[x]++;
    }
    
    int b;
    for(int x : nums) {
        b = k - x;
        if(b != x) {
            if(map.find(b) != map.end()) {
                return "YES";
            }
        }
        else {
            if(map[x] >= 2) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int>nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << algorithm(nums, k) << endl;
    
    return 0;
}
