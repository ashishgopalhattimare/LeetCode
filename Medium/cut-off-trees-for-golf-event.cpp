// https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Mock Test, Hard
// Current Complexity : (RC)^2 > TLE

struct Tree {
    int height, x, y;
    Tree(int h, int x, int y) : height(h), x(x), y(y) {}
};

class Solution {
public:
    
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    
    bool range(int x,int l) {
        return x >= 0 && x < l;
    }
    
    void bfs(int i, int j, int ti, int tj, vector<vector<int>>& forest, vector<vector<bool>>& visited, int distance, int *minDistance)
    {
        if(distance > *minDistance) return;
        
        if(i == ti && j == tj) {
            *minDistance = min(distance, *minDistance);
            return;
        }
        
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            if(range(i+X[k], forest.size()) && range(j+Y[k], forest[0].size()) && forest[i+X[k]][j+Y[k]] && !visited[i+X[k]][j+Y[k]]) {
                bfs(i+X[k],j+Y[k],ti,tj, forest, visited, distance+1, minDistance);
            }
        }
        visited[i][j] = false;
    }
    
    int cutOffTree(vector<vector<int>> forest) {
        
        if(forest[0][0] == 0) return -1;
        
        vector<vector<bool>>visited(forest.size());
        vector<Tree>nums;
        
        for(int i = 0; i < forest.size(); i++) {
            vector<bool>row(forest[i].size(), false);
            visited[i] = row;
            for(int j = 0; j < forest[i].size(); j++)
                if(forest[i][j] > 1)
                    nums.push_back({forest[i][j], i, j});
        }
        
        sort(nums.begin(), nums.end(), [](Tree& a, Tree& b) {
            return a.height < b.height;
        });
        
        int si = nums[0].x, sy = nums[0].y;
        int di, dy;
        
        int totalDistance, distance;
        
        distance = INT_MAX;
        bfs(0, 0, si, sy, forest, visited, 0, &distance);
        if(distance == INT_MAX) return -1;
        
        totalDistance = distance;
        
        for(int i = 0; i < nums.size(); i++) {
            di = nums[i].x; dy = nums[i].y;
            
            distance = INT_MAX;
            bfs(si, sy, di, dy, forest, visited, 0, &distance);
            if(distance == INT_MAX) {
                return -1;
            }
            forest[si][sy] = 1;
            
            totalDistance += distance;
            si = di; sy = dy;
        }
        
        return totalDistance;
    }
};
