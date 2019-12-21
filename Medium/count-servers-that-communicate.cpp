// https://leetcode.com/problems/count-servers-that-communicate/
// Medium

#define D2_int vector<vector<int>>&

class Solution {
private:
    const int DEFAULT = 1, VISITED = 3;
    int row, col;
    
public:
    int connect;
    
    // index valid or not
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
    void lineTraverse(D2_int G, int i, int j, int fi, int fj) {
        if(inrange(i, row) && inrange(j, col)) {
            
            // If the node is already visited, return
            if(G[i][j] == VISITED) return;
            
            // If the node is a computer, broadcast the message
            if(G[i][j] == DEFAULT) broadcast(G, i, j);

            // If non computer, follow the direction
            else
                lineTraverse(G, i+fi, j+fj, fi, fj);
        }
    }

    void broadcast(D2_int G, int i, int j)
    {
        // If the node is already visited, return
        if(G[i][j] == VISITED) return;
        
        G[i][j] = VISITED; // make it visited
        connect++; // increase the connected computers by 1
        
        // BroadCast in all directions
        lineTraverse(G, i+1, j, 1, 0); lineTraverse(G, i-1, j, -1, 0);
        lineTraverse(G, i, j+1, 0, 1); lineTraverse(G, i, j-1, 0, -1);
    }
    
    int countServers(D2_int grid) {
        
        row = grid.size(); col = grid[0].size();
        int result = 0, connected;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == DEFAULT){ // Valid Computer node
                
                    connect = 0; // count the connected computers
                    broadcast(grid, i, j); // broadcast the message
                    
                    // If more than one computers are connected
                    if(connect != 1) result += connect;
                }
            }
        }
        // Initialize the grid to initial state
        for(vector<int>& x : grid) for(int &y : x) if(y) y = DEFAULT;
        
        return result;
    }
};