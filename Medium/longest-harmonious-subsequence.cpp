// https://leetcode.com/problems/longest-harmonious-subsequence/
// Easy

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int>freq;
        
        // Store the frequency of each element
        for(int x : nums) freq[x]++;
        
        vector<pair<int,int>>arr;
        for(auto itr = freq.begin(); itr != freq.end(); itr++) {
            arr.push_back({itr->first, itr->second});
        }
        
        sort(arr.begin(), arr.end());
        
        int LHS = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i].first - arr[i-1].first == 1)
                LHS = max(LHS, arr[i].second + arr[i-1].second);
        }
        
        return LHS;
    }
};