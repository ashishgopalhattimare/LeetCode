// https://leetcode.com/problems/reshape-the-matrix/
// Easy

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        int Row = nums.size();
        int Col = nums[0].size();
        
        if(Row * Col != r * c) return nums;
        
        vector<vector<int>>result(r);
        for(int i = 0; i < r; i++)
        result[i] = vector<int>(c);
        
        for(int i = 0, k = 0; i < Row; i++) {
            for(int j = 0; j < Col; j++) {
                result[k/c][k%c] = nums[i][j];
                k++;
            }
        }
        
        return result;
    }
};
