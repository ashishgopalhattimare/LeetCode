// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Easy

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map1;
        unordered_map<int,int>map2;
        
        for(int x : nums1) map1[x]++;
        for(int x : nums2) map2[x]++;
        
        vector<int>result;
        int common;
        for(int x : nums2) {
            common = min(map1[x], map2[x]);
            if(common) {
                for(int i = 0; i < common; i++)
                result.push_back(x);
                
                map1[x]-=common;
                map2[x]-=common;
            }
        }
        return result;
    }
};
