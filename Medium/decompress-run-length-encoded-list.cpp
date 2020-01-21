// https://leetcode.com/problems/decompress-run-length-encoded-list/
// Easy

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        int n = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            n += nums[i];
        }
        
        vector<int>result(n);
        int k = 0;
        for(int i = 0; i < nums.size(); i+=2) {
            for(int j = 0; j < nums[i]; j++) {
                result[k++] = nums[i+1];
            }
        }
        
        return result;
    }
};