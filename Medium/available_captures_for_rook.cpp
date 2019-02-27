// https://leetcode.com/problems/available-captures-for-rook/description/

class Solution {
public:
    
    bool hit(int i, int j, int len, int I, int J, vector<vector<char>>& board)
    {
        for( ; i != len && j != len; i+=I, j+=J) {
            
            if(board[i][j] == '.') continue;
            if(board[i][j] == 'B') return 0;
            if(board[i][j] == 'p') {
                return true;
            }
        }
        return false;
    }
    
    int numRookCaptures(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.at(i).size(); j++) {
                
                if(board[i][j] == 'R') {
                    
                    return  hit(i+1, j, board.size(), 1, 0, board) + hit(i-1, j, -1, -1, 0, board) + 
                            hit(i, j+1, board[i].size(), 0, 1, board) + hit(i, j-1, -1, 0, -1, board);
                }
            }
        }
        
        return 0;
    }
};
