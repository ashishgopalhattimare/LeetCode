// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    
    int totalHammingDistance(vector<int>& nums) {
        
        int result = 0, totalbits;
        for(int i = 0; i < 32; i++) { // check all the bits
            totalbits = 0;
            for(int j = 0; j < nums.size(); j++) {
                // check if particular bit of each number is 1 or not
                totalbits += ((nums[j] >> i) & 1);
            }
            result += ((nums.size()-totalbits)*totalbits);
        }
        return result;
    }
};
