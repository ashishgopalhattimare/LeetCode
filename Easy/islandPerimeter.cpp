// https://leetcode.com/problems/island-perimeter/description/

class Solution {
public:
    
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    
    bool validRange(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    void traverseIsland(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int *perimeter)
    {
        visited[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            if(validRange(x+X[i], grid.size()) && validRange(y+Y[i], grid[x].size())) {
                if(visited[x+X[i]][y+Y[i]] == true) continue;
                else if(grid[x+X[i]][y+Y[i]] == 0) {
                    *perimeter = *perimeter + 1;
                }
                else {
                    traverseIsland(x+X[i], y+Y[i], grid, visited, perimeter);
                }
            }
            else {
                *perimeter = *perimeter + 1;
            }
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int perimeter = 0;
        
        vector<vector<bool>>visited;
        for(int i = 0; i < grid.size(); i++) {
            vector<bool>row(grid[i].size(), false);
            visited.push_back(row);
        }
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    traverseIsland(i, j, grid, visited, &perimeter);
                }
            }
        }
        
        return perimeter;
    }
};
