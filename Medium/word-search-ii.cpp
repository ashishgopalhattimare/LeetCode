// https://leetcode.com/problems/word-search-ii/
// Hard, BackTracking, HashMap

class Solution {
public:
    
    int X[4] = {-1,0,0,1};
    int Y[4] = {0,-1,1,0};
    
    bool inrange(int x, int l) {
        return x >= 0 && x < l;
    }
    
    bool backtrack(int i, int j, vector<vector<char>>& board, string& word, int index)
    {
        if(index == word.length()) {
            return true;
        }
        
        char c = board[i][j];
        board[i][j] = '.';
        
        for(int k = 0; k < 4; k++) {
            if(inrange(i+Y[k], board.size()) && inrange(j+X[k], board[0].size()) && board[i+Y[k]][j+X[k]] == word[index]) {
                if(backtrack(i+Y[k], j+X[k], board, word, index+1)) {
                    board[i][j] = c;
                    return true;
                }
            }
        }
        board[i][j] = c;
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        sort(words.begin(), words.end());
        
        vector<string>result;
        unordered_map<char, vector<pair<int,int>>>map;
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                
                map[board[i][j]].push_back(make_pair(i, j));
            }
        }
        
        for(string& x : words) {
            for(pair<int,int> p : map[x[0]]) {
                if(backtrack(p.first, p.second, board, x, 1)) {
                    result.push_back(x);
                    
                    break;
                }
            }
        }
        
        return result;
    }
};
