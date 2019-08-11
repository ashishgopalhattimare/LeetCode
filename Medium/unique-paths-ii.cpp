// https://leetcode.com/problems/unique-paths-ii/
// Medium
// Complexity : O(n^2)
// DP, Array

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
        
        int r = obstacleGrid.size(), c = obstacleGrid[0].size();
        
        vector<vector<long long int>> matrix(r, vector<long long int>(c, 0));
        
        for(int j = 0, obstacle = 0; j < c; j++) {
            if(!obstacleGrid[0][j] && !obstacle) {
                matrix[0][j] = 1;
            }
            else {
                obstacle =  true;
                matrix[0][j] = 0;
            }
        }
        
        for(int i = 0, obstacle = 0; i < r; i++) {
            if(!obstacleGrid[i][0] && !obstacle) {
                matrix[i][0] = 1;
            }
            else {
                obstacle =  true;
                matrix[i][0] = 0;
            }
        }
        
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(obstacleGrid[i][j]) {
                    matrix[i][j] = 0;
                }
                else matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]; // int overflow
            }
        }
        return matrix[r-1][c-1];
    }
};
