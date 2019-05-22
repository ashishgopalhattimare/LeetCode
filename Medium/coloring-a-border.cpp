// https://leetcode.com/problems/coloring-a-border/

class Solution {
public:
    
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    
    bool valid(int x, int n) {
        return x>=0 && x < n;
    }
    
    void bfs(vector<vector<int>>& grid, int r0, int c0, int color, int target, vector<vector<bool>>& visited) {
        
        visited[r0][c0] = true;
        grid[r0][c0] = color;
        
        for(int i = 0; i < 4; i++) {
            if(valid(r0+X[i], grid.size()) && valid(c0+Y[i], grid[0].size()) && grid[r0+X[i]][c0+Y[i]] == target) {
                bfs(grid, r0+X[i], c0+Y[i], color, target, visited);
            }
        }
        return;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& original, int r0, int c0, int color) {
        
        if(original[r0][c0] != color) {
            
            vector<vector<bool>>visited(original.size());
            vector<vector<int>>grid = original;

            for(int i = 0; i < grid.size(); i++) {
                vector<bool>brow(original[i].size(), false);
                visited[i] = brow;
            }
            
            bfs(grid, r0, c0, color, grid[r0][c0], visited);
            
            // copy the updated grid matrix
            vector<vector<int>> result = grid;

            bool allCover;
            for(int i = 1; i < grid.size()-1; i++) {
                for(int j = 1; j < grid[i].size()-1; j++) {

                    // look for any update from all 4-sides
                    // If yes, update the value back to original value
                    allCover = true;
                    for(int k = 0; k < 4; k++) {
                        if(grid[i+X[k]][j+Y[k]] != color || visited[i+X[k]][j+Y[k]] == false) {
                            allCover = false;
                            break;
                        }
                    }
                    if(allCover) result[i][j] = original[i][j];
                }
            }

            return result;
        }
        
        return original;
    }
};
