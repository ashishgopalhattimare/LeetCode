// https://leetcode.com/problems/rank-transform-of-an-array/
// Easy

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        if(arr.size() == 0) return {};
        
        vector<int>result(arr.size());
        
        // Use result array as temporary array to sort and precompute the result
        for(int i = 0; i < arr.size(); i++) {
            result[i] = arr[i];
        }
        sort(result.begin(), result.end());
        
        unordered_map<int,int>map;
        int rank = 1;
        
        map[result[0]] = rank;
        for(int i = 1; i < result.size(); i++) {
            if(result[i-1] != result[i])
                map[result[i]] = ++rank;
        }
        
        // use result array to store the result
        for(int i = 0; i < arr.size(); i++) result[i] = map[arr[i]];
        
        return result;
    }
};