// https://leetcode.com/problems/minimum-height-trees/description/

class Solution {
public:
    
    struct Vertex
    {
        int val;
        vector<int>ar;
        Vertex(int v) {
            val = v;
        }
    };
    
    void dfs(int source, vector<Vertex*>& arr, vector<bool>& visited, int* maxHeight, int *global, bool* earlyEnd, int currentHeight)
    {
        visited[source] = true;
        *maxHeight = max(*maxHeight, currentHeight);
        
	// EARLY END CONDITION AS THERE IS NO POINT OF FURTHER DFS
        if(*maxHeight > *global) {
            *earlyEnd = true;
            visited[source] = false;
            
            return;
        }
        
        for(int j = 0; j < arr[source]->ar.size() && *earlyEnd == false; j++) {
            if(visited[arr[source]->ar[j]] == false) {
                dfs(arr[source]->ar[j], arr, visited, maxHeight, global, earlyEnd, currentHeight+1);
            }
        }
        visited[source] = false;
        return;
    }
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        
        vector<bool>visited(n, false);
        vector<Vertex*>arr(n);
        
        for(int i = 0; i < n; i++) {
            arr[i] = new Vertex(i);
        }
        
        for(int i = 0; i < edges.size(); i++) {
            (arr[edges[i].first]->ar).push_back(edges[i].second);
            (arr[edges[i].second]->ar).push_back(edges[i].first);
        }
        
        vector<int>tempResult(n+1);
        int index;
        int globalMin = INT_MAX;
        
        bool earlyEnd;
        
        int maxHeight;
        for(int i = 0; i < n; i++) {
            maxHeight = 0;
            earlyEnd = false;
            dfs(i, arr, visited, &maxHeight, &globalMin, &earlyEnd, 0);
            
            if(maxHeight < globalMin) {
                globalMin = maxHeight;
                index = 0;
            }
            
            if(maxHeight == globalMin) {
                tempResult[index++] = i;
            }
        }
        
        vector<int>result;
        for(int i = 0; i < index; i++) {
            result.push_back(tempResult[i]);
        }
        
        return result;
    }
};