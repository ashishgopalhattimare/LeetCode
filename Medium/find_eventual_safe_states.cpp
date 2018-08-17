// https://leetcode.com/problems/find-eventual-safe-states/description/

// smart backtracking and use of stack DFS

class Solution {
public:
    
    bool repeat_node;
    
    bool DFS(int source, vector<vector<int>>& graph, bool *visited, unordered_set<int>& safe, unordered_set<int>& danger)
    {
        // is the node is already visited or the node is already unsafe to choose, return false
        if(danger.find(source) != danger.end() || visited[source]) {
            return false;
        }
        // if the node is already safe, return true -> dont go further because ahead nodes will also be safe and are
        // already marked safe
        if(safe.find(source) != safe.end()) {
            return true;
        }
        
        // make it visited
        visited[source] = true;
        
        // iterate through the nodes
        for(int i = 0; i < graph[source].size() && !repeat_node; i++) {
            if(!DFS(graph[source][i], graph, visited, safe, danger)) { // check whether it is safe or not
                danger.insert(graph[source][i]); // unsafe -> add it in danger set
                return false; // return false to the parent node call, implies parent is also unsafe to choose for future call
            }
            
        }
        
        // make it unvisited again
        visited[source] = false;
        
        safe.insert(source); // this node is safe -> add to safe node set
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        bool *visited = new bool[n];
        
        vector<int>result;
        unordered_set<int>safe, danger;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) visited[j] = false;
            
            // the node is not safe to choose
            if(danger.find(i) != danger.end()){
                continue;
            }
            if(safe.find(i) != safe.end()) {
                result.push_back(i);
                continue;
            }
            
            repeat_node = false;
            
            // check whether it is safe to choose or not
            if(!DFS(i, graph, visited, safe, danger)) {
                danger.insert(i); // not safe
            }
            // safe to choose
            else {
                safe.insert(i);
                result.push_back(i);
            }
        }
        
        return result;
    }
};