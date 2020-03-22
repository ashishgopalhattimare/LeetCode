// https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// Easy

class Solution {
public:
    
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        // Get minimum element in each row
        int index;
        for(int i = 0; i < row; i++) {
            index = 0;
            for(int j = 0; j < col; j++) {
                if(abs(matrix[i][index]) > abs(matrix[i][j])) {
                    index = j;
                }
            }
            
            // Got the row minimum value index, mark it negative
            matrix[i][index] = -matrix[i][index];
        }
        
        vector<int>result;
        
        for(int j = 0; j < col; j++) {
            index = 0;
            for(int i = 0; i < row; i++) {
                if(abs(matrix[index][j]) < abs(matrix[i][j])) {
                    index = i;
                }
            }
            
            // If negative, one of the lucky numbers
            if(matrix[index][j] < 0) result.push_back(abs(matrix[index][j]));
        }
        
        for(vector<int>& x : matrix) for(int &y : x) y = abs(y);
        
        return result;
    }
};