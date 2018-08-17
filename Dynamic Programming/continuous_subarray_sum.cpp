// https://leetcode.com/problems/continuous-subarray-sum/description/

// Modulo K and subarray sum property -> a range of mutiplied by K has modulo same at either ends

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() == 0 || nums.size() == 1) return false;
        
        if(k == 0) {
            for(int i = 0; i < nums.size()-1; i++) {
                if(nums[i] == 0 && nums[i+1] == 0) {
                    return true;
                }
            }
            return false;
        }
        
        unordered_map<int,int>hash;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(hash.find(sum%k) != hash.end() || (sum % k == 0)) {
                if(i - hash[sum%k] >= 1) return true;
            }
            else hash[sum%k] = i;
        }
        
        return false;
    }
};