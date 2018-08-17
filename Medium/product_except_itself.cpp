// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int zeroes = 0;
        
        long long int product = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) zeroes++;
            else {
                product *= nums[i];
            }
        }
        
        vector<int>result(nums.size(), 0);
        
        if(zeroes > 1) {
            return result;
        }
        if(zeroes == 1) {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    result[i] = product;
                }
            }
        }
        else {
            for(int i = 0; i < nums.size(); i++) {
                result[i] = product/nums[i];
            }
        }
        
        return result;
    }
};