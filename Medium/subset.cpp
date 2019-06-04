// Mock Test
// Iterative, and power bit solution
// Alternative : recursive,backtrack

class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        
        int value, index;
        for(int i = 0; i < pow(2, nums.size()); i++) {
            value = i;
            index = 0;
            vector<int>row;
            while(value) {
                if(value&1) {
                    row.push_back(nums[index]);
                }
                value >>= 1;
                index++;
            }
            result.push_back(row);
        }
        return result;
    }
};
