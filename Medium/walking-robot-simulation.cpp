// https://leetcode.com/problems/walking-robot-simulation/
// Easy

class Solution {
public:
    
    vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int k = 0, mod = 4;
        int x = 0, y = 0;
        int nextx, nexty;
        
        unordered_map<int,unordered_set<int>>map;
        for(vector<int> x : obstacles) {
            map[x[0]].insert(x[1]);
        }
        
        int maxDistance = 0;
        for(int input : commands) {
            switch(input) {
                case -2: // turn left 90 degree
                    k = (k + 3) % mod;
                    break;
                    
                case -1: // turn right 90 degree
                    k = (k+1)%mod;
                    break;
                
                default:
                    for(int i = 0; i < input; i++) {
                        nextx = x + dir[k][0];
                        nexty = y + dir[k][1];
                        if(map.find(nextx) != map.end() && 
                           map[nextx].find(nexty) != map[nextx].end()) {
                            break;
                        }
                        else {
                            x = nextx; y = nexty;
                        }
                    }
                    
                    maxDistance = max(maxDistance, x*x + y*y);
            }
        }
        
        return maxDistance;
    }
};
