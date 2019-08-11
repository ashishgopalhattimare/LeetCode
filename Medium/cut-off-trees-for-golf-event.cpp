// https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Hard

struct Tree {
    int height, x, y;
    Tree(int h, int x, int y) : height(h), x(x), y(y) {}
};

class Solution {
public:
    
    int X[4] = {-1,1,0,0};
    int Y[4] = {0,0,-1,1};
    
    int result = 0;
    
    bool inrange(int x, int l) {
        return x >= 0 && x < l;
    }
    
    bool bfs(vector<vector<int>>& forest, int &starti, int &startj, int endi, int endj, vector<vector<int>>&visit, int id)
    {
        list<vector<int>>ll; // bfs
        vector<int>curr; // index
        int i, j;
        
        ll.push_back({starti, startj, 0});
        visit[starti][startj] = id;
        
        bool found = false;
        
        while(!ll.empty()) {
            curr = ll.front();
            ll.pop_front();
            
            if(endi == curr[0] && endj == curr[1]) {
                result += curr[2];
                starti = curr[0]; startj = curr[1];
                
                found = true;
                break;
            }
            
            for(int k = 0; k < 4; k++) {
                i = curr[0] + Y[k];
                j = curr[1] + X[k];
                
                if(inrange(i, forest.size()) && inrange(j, forest[0].size()) && visit[i][j] != id && forest[i][j]) {
                    ll.push_back({i, j, curr[2]+1});
                    
                    visit[i][j] = id;
                }
            }
        }
        return found;
    }
    
    int cutOffTree(vector<vector<int>> forest) {
        
        if(forest[0][0] == 0) return -1;
        
        vector<vector<int>>visit(forest.size(), vector<int>(forest[0].size(), 0));
        vector<Tree>nums;
        
        for(int i = 0; i < forest.size(); i++) {
            for(int j = 0; j < forest[i].size(); j++)
                if(forest[i][j] > 1) // Tree Identity
                    nums.push_back({forest[i][j], i, j});
        }
        
        sort(nums.begin(), nums.end(), [](Tree& a, Tree& b) {
            return a.height < b.height;
        });
        
        int sourcei = 0, sourcej = 0;
        
        // printf("%d %d\n", nums[0].x, nums[0].y);
        
        // Go the source first, if possible
        int id = 2;
        if(bfs(forest, sourcei, sourcej, nums[0].x, nums[0].y, visit, id++)) {
            for(Tree tree : nums) {
                if(!bfs(forest, sourcei, sourcej, tree.x, tree.y, visit, id++)) {
                    return -1;
                }
            }
        }
        else return -1;
        
        return result;
    }
};
