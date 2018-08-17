// https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<char>>direction;
        vector<vector<int>>summation;
        
        for(int i = 0; i < grid.size(); i++) {
            vector<char>dir(grid[i].size(),'x');
            vector<int>sum(grid[i].size(), 0);
            
            summation.push_back(sum);
            direction.push_back(dir);
        }
        
        summation[0][0] = grid[0][0];
        
        for(int j = 1; j < grid[0].size(); j++) {
            summation[0][j] = summation[0][j-1] + grid[0][j];
            direction[0][j] = 'L';
        }
        for(int i = 1; i < grid.size(); i++) {
            summation[i][0] = summation[i-1][0] + grid[i][0];
            direction[i][0] = 'U';
        }
        
        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[i].size(); j++) {
                if(summation[i-1][j] < summation[i][j-1]) {
                    summation[i][j] = summation[i-1][j] + grid[i][j];
                    direction[i][j] = 'U';
                }
                else {
                    summation[i][j] = summation[i][j-1] + grid[i][j];
                    direction[i][j] = 'L';
                }
            }
        }
        
        return summation[grid.size()-1][grid[0].size()-1];
    }
};