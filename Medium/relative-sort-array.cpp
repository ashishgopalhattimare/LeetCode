// https://leetcode.com/problems/relative-sort-array/
// Easy

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>map;
        
        for(int x : arr2) map[x] = 0;
        for(int x : arr1) if(map.find(x) != map.end()) map[x]++;
        
        vector<int>result(arr1.size());
        int k = 0;
        for(int x : arr2) while(map[x]--) result[k++] = x;
        
        int start = k;
        for(int x : arr1) if(map.find(x) == map.end()) result[k++] = x;
        
        sort(result.begin()+start, result.end());
        return result;
    }
};
