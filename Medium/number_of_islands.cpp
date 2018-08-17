// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
    
    int dirX[4] = {-1,0,0,1};
    int dirY[4] = {0,1,-1,0};
    
    bool in_range(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    void travelPath(int i, int j, vector<vector<char>>& grid, int row, int col)
    {
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++) {
            if(in_range(i+dirY[k], row) && in_range(j+dirX[k], col)) {
                if(grid[i+dirY[k]][j+dirX[k]] == '1') {
                    travelPath(i+dirY[k], j+dirX[k], grid, row, col);
                }
            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    travelPath(i, j, grid, row, col);
                    count++;
                }
            }
        }
        
        return count;
    }
};