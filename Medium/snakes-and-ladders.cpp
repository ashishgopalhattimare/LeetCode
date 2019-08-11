// https://leetcode.com/problems/snakes-and-ladders/
// Medium

class Solution {
public:
    
    void print(vector<int>& board) {
        for(int i = 1; i < board.size(); i++) {
            printf("[%d,%d] ", i, board[i]);
        }
        printf("\n");
    }

    void GameOn(vector<int>& game, vector<int>& grid, int start, bool ladder) {
        int prev, curr, step;

        for(int i = 6; i > 0; i--) { // start taking each value
            
            if(!ladder) {
                prev = curr = start;
            }
            else {
                prev = curr = game[start];
            }
            
            if(grid[start] == INT_MAX) break;
            step = grid[start] + 1;
            
            if(curr == grid.size()-1) {
                grid[curr] = min(grid[curr], step);
            }

            unordered_map<int,unordered_set<int>>map;
            
            while(curr < grid.size()) {
                curr += i;
                
                for(int j = prev+1; j <= curr && j < grid.size(); j++) { // fill each with steps
                    grid[j] = min(grid[j], step);
                }
                
                if(curr == grid.size()-1) break;
                
                if(curr < grid.size() && game[curr] != -1) {
                    
                    if(game[curr] < curr) { // snake move
                        if(map.find(curr) != map.end() && 
                           map[curr].find(game[curr]) != map[curr].end()) {
                            break;
                        }
                        else {
                            map[curr].insert(game[curr]);
                        }
                    }
                    
                    curr = game[curr];
                    grid[curr] = min(grid[curr], step);
                }
                prev = curr;
                step++;
            }
        }
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        // Convert Grid to a single list
        vector<int>game(board.size()*board.size()+1, -1);
        vector<int>grid(board.size()*board.size()+1, INT_MAX);
        
        bool l2r = true;
        int start, end, factor;
        int index = 1;

        grid[1] = 0;

        vector<int>initialPos = {1};

        for(int i = board.size()-1; i >= 0; i--) {
            if(l2r) {
                start = 0; end = board.size();
                factor = 1;
            }
            else {
                start = board.size()-1; end = -1;
                factor = -1;
            }
            
            for(int j = start; j != end; j += factor) {
                if(board[i][j] != -1) {
                    game[index] = board[i][j];
                    if(board[i][j] > index) initialPos.push_back(index);
                }
                index++;
            }   
            l2r = !(l2r);
        }
        
        for(int i = 0; i < initialPos.size(); i++) {
            GameOn(game, grid, initialPos[i], i > 0);
        }
        
        print(grid);
        print(game);
        
        return (grid[grid.size()-1] == INT_MAX) ? -1 : grid[grid.size()-1];
    }
};