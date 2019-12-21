// https://leetcode.com/problems/shift-2d-grid/
// Easy

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        int top, mid, low;
        
        vector<int>lastCol(m);
        
        while(k--) {
            for(int i = 0; i < m; i++)
                lastCol[i] = grid[i][n-1];
            
            for(int j = n-2; j >= 0; j--){
                for(int i = 0; i < m; i++)
                    grid[i][j+1] = grid[i][j];
            }
            
            for(int i = 0; i < m; i++)
                grid[(i+1)%m][0] = lastCol[i];
        }
        
        return grid;
    }
};