// https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Easy

class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        unordered_map<int,int>mapi;
        for(int x : arr) mapi[x]++;
        
        int maxim = -1;
        for(auto itr = mapi.begin(); itr != mapi.end(); itr++) {
            if(itr->first == itr->second)
                maxim = max(maxim, itr->first);
        }
        
        return maxim;
    }
};