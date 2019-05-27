// https://leetcode.com/problems/friend-circles/
// Union-Find, Mock Test

class Solution {
public:
    
    int find(vector<int>& parent, int p) 
    {
        return parent[p]==-1 ? p : find(parent, parent[p]);
    }
    
    int findCircleNum(vector<vector<int>>& M) 
    {
        vector<int> parent(M.size(),-1);
        int N = M.size();
        
        for(int i=0; i < M.size(); i++)
        {
            for(int j=0; j < M.size(); j++)
            {
                if(M[i][j])
                {
                    int u = find(parent,i);
                    int v = find(parent,j);
                    if(v ^ u) {
                        parent[v] = u;
                    }
                }
            }
        }
        return count(parent.begin(), parent.end(), -1);
    }
};
