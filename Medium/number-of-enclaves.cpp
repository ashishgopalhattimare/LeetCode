// https://leetcode.com/problems/number-of-enclaves/
// Medium
// Complexity : DFS (Accepted), BFS (TLE)

class Solution {
public:
    
    int X[4] = {0,-1,1,0};
    int Y[4] = {-1,0,0,1};
    
    bool inrange(int x, int l) { return x >= 0 && x < l; }
    
    void bfs(vector<vector<int>>& A, int ii, int jj, int fi, int fj) {
        for(int i = ii, j = jj; i != A.size() && j != A[0].size(); i += fi, j += fj) {
            if(A[i][j]) allZero(A, i, j);
        }
    }
    
    void allZero(vector<vector<int>>& A, int i, int j)
    {
        list<pair<int,int>>ll;
        pair<int,int>curr;
        
        ll.push_back({i, j});
        
        while(!ll.empty()) {
            curr = ll.front();
            ll.pop_front();
            A[curr.first][curr.second] = 0;
            
            for(int k = 0; k < 4; k++) {
                i = curr.first + Y[k];
                j = curr.second+ X[k];
                
                if(inrange(i, A.size()) && inrange(j, A[0].size()) && A[i][j]) {
                    ll.push_front({i, j});  // DFS - Accepted
                  //ll.push_back({i, j});   // BFS - TLE

                }
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        
        if(A.size() == 0) return 0;
        
        bfs(A, 0, 0, 0, 1); // first row
        bfs(A, 0, 0, 1, 0); // first col
        
        bfs(A, A.size()-1, 0, 0, 1);     // last row
        bfs(A, 0, A[0].size()-1, 1, 0);  // last col
        
        int count = 0;
        for(vector<int> x : A) for(int a : x) count += (a == 1);
        
        return count;
    }
};
