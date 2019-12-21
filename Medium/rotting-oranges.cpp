// https://leetcode.com/problems/rotting-oranges/
// Easy

#define FRESH 1
#define ROTEN 2

class Solution {
public:
    
    int X[4] = {0,0,1,-1};
    int Y[4] = {-1,1,0,0};
    
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
    int orangesRotting(vector<vector<int>> grid) {
        
        int row = grid.size(), col = grid[0].size();
        list<vector<int>>ll;
        vector<int> cur;
            
        int freshOrange = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == FRESH) freshOrange++; // Fresh Orange count
                else if(grid[i][j]) // Rotten Oranges
                    ll.push_back({i, j, 0});
            }
        }
        
        int timeTaken = 0;
        while(!ll.empty()) {
            cur = ll.front();
            ll.pop_front();
            
            timeTaken = cur[2];
            
            for(int k = 0; k < 4; k++) {
                if(inrange(cur[0]+Y[k], row) && inrange(cur[1]+X[k], col) &&
                  grid[cur[0]+Y[k]][cur[1]+X[k]] == FRESH) {
                    
                    grid[cur[0]+Y[k]][cur[1]+X[k]] = ROTEN;
                    freshOrange--; //Fresh to Roten
                    ll.push_back({cur[0]+Y[k], cur[1]+X[k], cur[2]+1});
                }
            }
        }
        
        return (freshOrange > 0) ? -1 : timeTaken;
    }
};