// https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Medium, Weekly Contest 141

struct Node {
    int i, j, path;
    Node(int i, int j, int path) : i(i), j(j), path(path) {}
};

class Solution {
public:
    int n;
    bool found = 0;
    int minim = INT_MAX;
    
    int x[8] = {-1,0,1,-1,1,-1,0,1};
    int y[8] = {-1,-1,-1,0,0,1,1,1};
    
    bool range(int k) {
        return k >= 0 && k < n;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        
        vector<vector<bool>>inlist(n);
        for(int i=0;i<n;i++)
            inlist[i] = vector<bool>(n, false);
        
        list<Node*>ll;
        
        ll.push_back(new Node(0,0,1));
        inlist[0][0] = true;
        
        int i, j, path, result = -1;
        Node *curr;
        
        while(!ll.empty()) {
            curr = ll.front();
            ll.pop_front();
            
            i = curr->i; j = curr->j, path = curr->path;
            
            if(i == n-1 && j == n-1) {
                result = path;
                delete curr;
                break;
            }
            
            for(int k = 0; k < 8; k++) {
                if(range(i+x[k]) && range(j+y[k]) && !inlist[i+x[k]][j+y[k]] && !grid[i+x[k]][j+y[k]]) {
                    ll.push_back(new Node(i+x[k], j+y[k], path+1));
                    inlist[i+x[k]][j+y[k]] = true;
                }
            }
            
            delete curr;
        }
        
        while(!ll.empty()) {
            curr = ll.front();
            ll.pop_front();
            delete curr;
        }
        
        return result;
    }
};
