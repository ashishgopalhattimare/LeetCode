class Solution {
public:
    
    int X[4] = {0,0,-1,1};
    int Y[4] = {-1,1,0,0};
    
    bool valid(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        board[i][j] = 'Z';
        
        for(int k = 0; k != 4; k++) {
            if(valid(i+X[k], board.size()) && valid(j+Y[k], board[i].size()) && board[i+X[k]][j+Y[k]] == 'O') {
                dfs(i+X[k], j+Y[k], board);
            }
        }
        return;
    }
    
    void solve(vector<vector<char>>& board) {
        
        if(board.size() == 0) return;
        
        // Starting Make Collection of O's from the borders and change then to 'Z'
        
        for(int i = 0; i < board.size(); i++) {
            if(board[i][0] == 'O') {
                dfs(i, 0, board);
            }
        }
        for(int i = 0; i < board.size(); i++) {
            if(board[i][board[i].size()-1] == 'O') {
                dfs(i, board[i].size()-1, board);
            }
        }
        
        for(int j = 0; j < board[0].size(); j++) {
            if(board[0][j] == 'O') {
                dfs(0, j, board);
            }
        }
        for(int j = 0; j < board[0].size(); j++) {
            if(board[board.size()-1][j] == 'O') {
                dfs(board.size()-1, j, board);
            }
        }
        
        // Everything other than 'Z' on the board are 'X' and the 'Z' are turned to 'O'
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'Z') board[i][j] = 'O';
                else {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
