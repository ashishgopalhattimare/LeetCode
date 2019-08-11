// https://leetcode.com/problems/path-with-maximum-minimum-value/
// Medium
// Binary Search + BFS
// Weekly Contest

class Solution {
public:
    int X[4] = {-1,0,0,1};
    int Y[4] = {0,-1,1,0};
    
    int r, c;
    bool inrange(int x, int l) {
        return x >= 0 && x < l;
    }
    
    bool bfs(int mid, vector<vector<int>>& A)
    {
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        if(A[0][0] < mid) return false;
        
        list<vector<int>>ll;
        
        ll.push_back({0,0});
        visited[0][0] = 1;
        
        while(!ll.empty()) {
            vector<int> ptr = ll.front();
            ll.pop_front();
            
            for(int k = 0; k < 4; k++) {
                if(inrange(ptr[0]+Y[k], r) && inrange(ptr[1]+X[k], c) && !visited[ptr[0]+Y[k]][ptr[1]+X[k]] && A[ptr[0]+Y[k]][ptr[1]+X[k]] >= mid) {
                    visited[ptr[0]+Y[k]][ptr[1]+X[k]] = 1;
                    ll.push_back({ptr[0]+Y[k], ptr[1]+X[k]});
                }
            }
        }
        
        return visited[r-1][c-1];
    }
    
    int maximumMinimumPath(vector<vector<int>>& A) {
        
        c = A[0].size();
        r = A.size();
        
        int low = 0, high = 0;
        int minim = 0;
        
        for(vector<int> x : A) for(int y : x) high = max(high, y);
        
        // Find the value that is minimum in the path from start to end that is present in the path
        
        // 5->4->5->6->6 - in this 1 2 3 4 are all the minimum valid values but only 4 is present
        
        // Binary Search to find the optimal maximum minimum in the bfs
        while(low <= high) {
            int mid = (low+high+1) >> 1;
            if(bfs(mid, A)) { // check if mid is the lowest value in the bfs of the matrix
                low = mid+1;
                minim = max(minim, mid);
            } // if not
            else high = mid-1;
        }
        
        return minim;
    }
};
