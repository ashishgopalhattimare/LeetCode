// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
// Medium
// Weekly Contest
// Disjoint Set

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0]; 
        });
        
        vector<int>group(N);
        for(int i = 0; i < N; i++) {
            group[i] = i;
        }
        
        int currentGroup;
        bool allSame;
        for(vector<int> log : logs) { // O(10^4)
            if(group[log[1]] == group[log[2]]) continue;
            
            currentGroup = group[log[2]];
            allSame = true;
            for(int i = 0; i < N; i++) { //O(100)
                if(group[i] == currentGroup) {
                    group[i] = group[log[1]];
                }
                
                if(group[log[1]] != group[i]) {
                    allSame = false;
                }
            }
            
            if(allSame) return log[0];
        }
        
        return -1;
    }
};
