// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Easy

class Solution {
public:
    
    int binary_search(vector<int>arr, int low, int high) {
        
        if(low == high) {
            return (arr[low] == 1) ? low + 1 : 0;   
        }
        else if(high == low+1) {
            if(arr[high] == 1) return high + 1;
            return (arr[low] == 1) ? low + 1 : 0;
        }
        
        int mid = low + (high-low)/2;
        if(arr[mid] == 1) return binary_search(arr, mid, high);
        return binary_search(arr, low, mid);
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> order(mat.size());
        for(int i = 0; i < mat.size(); i++) {
            order[i] = {i, binary_search(mat[i], 0, mat[i].size()-1)};
        }
        
        sort(order.begin(), order.end(), [](pair<int,int>& a, pair<int,int>& b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        
        vector<int>result(k);
        for(int i = 0; i < k; i++) result[i] = order[i].first;
        
        return result;
    }
};

// [2,0,3,1,4]
// [1,2,3,4,5]