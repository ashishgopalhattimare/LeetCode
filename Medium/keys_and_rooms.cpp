// https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    
    void DFS(int i, vector<vector<int> >& rooms, bool *visited)
    {
        visited[i] = true;
        
        for(int j = 0; j < rooms[i].size(); j++) {
            if(!visited[rooms[i][j]]) {
                DFS(rooms[i][j], rooms, visited);
            }
        }
        return;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        bool *visited = new bool[n];
        for(int i = 0; i < n; i++) {
            visited[i] = false;
        }
        
        DFS(0, rooms, visited);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) return false;
        }
        
        return true;
    }
};