// https://leetcode.com/problems/single-number-ii/
// Medium

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int>map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        
        for(auto itr : map) {
            if(itr.second == 1)
            return itr.first;
        }
        return -1;
    }
};
