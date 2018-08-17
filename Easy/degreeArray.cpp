// https://leetcode.com/problems/degree-of-an-array/description/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        unordered_map<int, int>hash;
        vector<int>maxV(50000);
        
        vector<int>start(50000);
        vector<int>end(50000);
        
        int index;
        int maxim = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = 1;
                
                start[nums[i]] = i;
            }
            else {
                hash[nums[i]]++;
            }
            end[nums[i]] = i;
            
            if(maxim < hash[nums[i]]) {
                index = 0;
                maxV[index++] = nums[i];
                
                maxim = hash[nums[i]];
            }
            else if(maxim == hash[nums[i]]) {
                maxV[index++] = nums[i];
            }
        }
        
        int minGap = INT_MAX;
        
        for(int i = 0; i < index; i++) {
            minGap = min(minGap, abs(end[maxV[i]] - start[maxV[i]]) + 1);
        }
        
        return minGap;
    }
};