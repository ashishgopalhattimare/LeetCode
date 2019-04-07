// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    
    bool checkValidV(int a, int b, char x, int j, vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            if(a == i && b == j) continue;
            if(board[i][j] == x) {
                return false;
            }
        }
        return true;
    }
    
    bool checkValidH(int a, int b, char x, int i, vector<vector<char>>& board) {
        for(int j = 0; j < board.size(); j++) {
            if(a == i && b == j) continue;
            if(board[i][j] == x) {
                return false;
            }
        }
        return true;
    }
    
    bool checkValidB(int a, int b, char x, int i, int j, vector<vector<char>>& board)
    {
        for(int I = 0; I < 3; I++) {
            for(int J = 0; J < 3; J++) {
                if(a == i+I && b == j+J) continue;
                if(board[i+I][j+J] == x) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        char x;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == '.') continue;
                
                x = board[i][j];  
                if(!(checkValidV(i, j, x, j, board) && checkValidH(i, j, x, i, board) && checkValidB(i, j, x, (i/3)*3,(j/3)*3, board))) {
                    return false;
                }
            }
        }
        
        return true;
    }
};