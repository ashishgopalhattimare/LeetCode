// https://leetcode.com/problems/toeplitz-matrix/description/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        return true;
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = matrix[i].size()-1; j > 0; j--) {
                if(matrix[i-1][j-1] != matrix[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};