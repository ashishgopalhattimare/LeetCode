// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>board;
        
        for(int i = 0; i < n; i++) {
            vector<int>row(m, 1);
            board.push_back(row);
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                board[i][j] = board[i-1][j] + board[i][j-1];
            }
        }
        
        return board[n-1][m-1];
    }
};