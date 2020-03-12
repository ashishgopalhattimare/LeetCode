// https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Medium

class Solution {
public:
    
    int maxTime = INT_MIN;
    
    void traversal(int src, vector<vector<int>>& person, vector<int>& informTime, int time)
    {
        for(int x : person[src])
            traversal(x, person, informTime, time + informTime[x]);
        
        maxTime = max(maxTime, time);
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>person(n);
        
        int headManager;
        for(int i = 0 ; i < n; i++) {
            if(manager[i] == -1)
                headManager = i;
            else {
                person[manager[i]].push_back(i);
            }
        }
        
        traversal(headManager, person, informTime, informTime[headManager]);
        return maxTime;
    }
};

