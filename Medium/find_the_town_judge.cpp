// https://leetcode.com/contest/weekly-contest-125/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        vector<bool> isjudge (N, true);
        vector<int> upvotes(N, 0);
        
        for(int i = 0; i < trust.size(); i++) {
            
            isjudge[trust[i][0]-1] = false;
            upvotes[trust[i][1]-1]++;
        }
        
        for(int i = 0; i < upvotes.size(); i++) {
            if(isjudge[i] && upvotes[i] == N-1) {
                return i+1;
            }
        }
        
        return -1;
    }
};
