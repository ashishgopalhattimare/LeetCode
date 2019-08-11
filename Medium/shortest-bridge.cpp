// https://leetcode.com/problems/shortest-bridge/
// Medium
// Better BFS leading to optimization

class Solution {
public:
    
    int X[4] = {-1,0,0,1};
    int Y[4] = {0,-1,1,0};
    
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
    void print(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    int algorithm(int i, int j, vector<vector<int>>& A)
    {
        int row = A.size(), col = A[0].size();
        
        list<pair<int,int>>intermediate;
        list<vector<int>>ll;
        pair<int,int>curr;
        
        intermediate.push_back({i, j});
        
        bool borderPush;
        while(!intermediate.empty()) {
            curr = intermediate.front();
            intermediate.pop_front();
            
            // Change their value to 2
            A[curr.first][curr.second] = 2;
            
            borderPush = false;
            for(int k = 0; k < 4; k++) {
                i = curr.first + Y[k];
                j = curr.second+ X[k];
                
                if(inrange(i, row) && inrange(j, col)) {
                    // Insland Inside
                    if(A[i][j] == 1) {
                        intermediate.push_back({i, j});
                        A[i][j] = 2;
                    }
                    // Island Border
                    else if(A[i][j] == 0 && !borderPush){
                        ll.push_back({curr.first, curr.second, 0});
                        borderPush = true;
                    }
                }
            }
        }
        
        // At the end of the above, only the border of the island are there
        // for the shortest path
        
        vector<int>cur;
        while(!ll.empty()) {
            cur = ll.front();
            ll.pop_front();
            
            for(int k = 0; k < 4; k++) {
                i = cur[0] + Y[k];
                j = cur[1] + X[k];
                
                if(inrange(i, row) && inrange(j, col)) {
                    if(A[i][j] == 0) { // still water
                        ll.push_back({i, j, cur[2]+1});
                        A[i][j] = 3;
                    }
                    
                    // Second Island found
                    else if(A[i][j] == 1)return cur[2];
                }
            }
        }
        
        return 0;
    }
    
    
    // Two Islands are always separated
    int shortestBridge(vector<vector<int>>& A) {
        
        bool found =  false;
        for(int i = 0; i < A.size() && !found; i++) {
            for(int j = 0; j < A[i].size() && !found; j++) {
                if(A[i][j] == 1) { // One island found
                    
                    return algorithm(i, j, A);
                }
            }
        }
        
        return 0;
    }
};
