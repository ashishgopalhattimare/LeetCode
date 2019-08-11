// https://leetcode.com/problems/battleships-in-a-board/
// Medium

class Solution {
public:
    
    void eliminateShip(vector<vector<char>>& board, int i, int j) {
        
        for(int k = i; k < board.size(); k++) {
            if(board[k][j] != 'X') break;
            board[k][j] = 'x';
        }
        for(int k = j+1; k < board[i].size(); k++) {
            if(board[i][k] != 'X') break;
            board[i][k] = 'x';
        }
    }
    
    int countBattleships(vector<vector<char>> board) {
        
        int countShips = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == 'X') {
                    
                    if(i > 0 && board[i-1][j] == 'X') continue; // all ships are seperate island
                    if(j > 0 && board[i][j-1] == 'X') continue; // all ships are separate island
                    
                    countShips++;
                    
                }
            }
        }
        
        return countShips;
    }
};
