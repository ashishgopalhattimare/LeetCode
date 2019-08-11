// https://leetcode.com/contest/weekly-contest-147/problems/largest-1-bordered-square/
// Medium

class Solution {
public:
    
    int kadane(vector<int>& temp1, vector<vector<int>>& grid, int stretch, int L, int R)
    {
        int maxim = 0, square;
        for(int i = 0; i + stretch < temp1.size(); i++) {
            if(temp1[i] == 1 && temp1[i+stretch] == 1) { // top and bottom row are all one
                square = true;
                for(int k = i+1; k < i+stretch && square; k++) {
                    if(grid[k][L] != 1 || grid[k][R] != 1)
                        square = false;
                }
                
                if(square) maxim = max(maxim, (stretch+1) * (stretch+1));
            }
        }
        return maxim;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        
        if(grid.size() == 0) return 0;
        
        int maxim = 0, index;
        int ROW = grid.size(), COL = grid[0].size();
        
        vector<int>temp1(ROW);
        for(int left = 0; left < COL; left++) {
            
            for(int& x : temp1) x = 1;
            
            for(int right = left; right < COL; right++) {
                
                for(int k = 0; k < ROW; k++) {
                    temp1[k] = temp1[k] & grid[k][right];
                }
                
                maxim = max(maxim, kadane(temp1, grid, right-left, left, right));
            }
        }
        
        return maxim;
    }
};
