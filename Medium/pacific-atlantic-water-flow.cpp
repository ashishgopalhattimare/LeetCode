// https://leetcode.com/problems/pacific-atlantic-water-flow/
// Medium
// BFS O(n^2)

class Solution {
public:
    
    int X[4] = {0,1,-1,0};
    int Y[4] = {-1,0,0,1};
    
    bool inrange(int x, int limit) {
        return x >= 0 && x < limit;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<short>>& status, bool side, int s) {
        
        list<vector<int>>ll;
        int row, col;
        
        if(side) { // pacific - 2
            row = col = 0;
        }
        else {
            col = matrix[0].size()-1;
            row = matrix.size()-1;
        }
        
        for(int j = 0; j < matrix[0].size(); j++) { // fill the row
            ll.push_back({row, j});
        }
        
        for(int i = 0; i < matrix.size(); i++) { // fill the column
            ll.push_back({i, col});
        }
        
        vector<int>curr;
        int i, j;
        while(!ll.empty()) {
            
            curr = ll.front(); // <i, j>
            ll.pop_front();
            
            status[curr[0]][curr[1]] |= s;
            
            for(int k = 0; k < 4; k++) {
                i = curr[0]+Y[k];
                j = curr[1]+X[k];
                
                if(inrange(i, matrix.size()) && inrange(j, matrix[0].size()) &&
                  (status[i][j] != 3 && status[i][j] != s) && 
                   matrix[i][j] >= matrix[curr[0]][curr[1]])
                {
                    ll.push_back({i, j});
                }
            }
        }
        
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0) return {};
        
        vector<vector<short>>status(matrix.size(), vector<short>(matrix[0].size(), 0));
        
        // pacific Condition
        dfs(matrix, status, false, 1);
        dfs(matrix, status, true, 2);
        
        vector<vector<int>> result;
        for(int i = 0; i < status.size(); i++) {
            for(int j = 0; j < status[i].size(); j++) {
                if(status[i][j] == 3) {
                    result.push_back({i,j});
                }
            }
        }
        
        return result;
    }
};
