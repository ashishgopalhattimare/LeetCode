// https://leetcode.com/problems/number-of-closed-islands/
// Medium

#define D2_int vector<vector<int>>&

class Solution {
private:
    const int WATER = 1, LAND = 0, V_LAND = 2;
    
    vector<int> X = {0,0,1,-1};
    vector<int> Y = {1,-1,0,0};
    int row, col;
    bool isIsland;
    
public:
    
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
    void dfs(int i, int j, D2_int G)
    {
        // Island going out of the grid, consider it not closed island
        if(!inrange(i, row) || !inrange(j, col)) {
            isIsland = false;
            return;
        }
        
        // If water or already visited, return
        if(G[i][j] == WATER || G[i][j] == V_LAND)
            return;
        
        G[i][j] = V_LAND; // make the land visited

        // Traverse all directions
        for(int k = 0; k < 4; k++) dfs(i+Y[k], j+X[k], G);
        
        return;
    }
    
    int closedIsland(D2_int grid) {
        
        row = grid.size(); col = grid[0].size();
        int result = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                
                if(grid[i][j] == LAND) {
                    isIsland = true; // consider it be an bordered-island
                    dfs(i, j, grid);
                    
                    result += isIsland; // found an enclosed island, count it
                }
            }
        }
        
        for(vector<int>& x : grid) for(int &y : x) if(y == 2) y = LAND;
        
        return result;
    }
};