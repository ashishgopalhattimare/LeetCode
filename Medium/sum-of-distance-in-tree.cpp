// https://leetcode.com/problems/sum-of-distances-in-tree/
// Time Limit Exceeded O(n^2)
// Hard, optimal O(n)

struct Node
{
    vector<int>child;
    Node() {}
};

class Solution {
public:
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {

        vector<vector<int>>matrix(N, vector<int>(N, INT_MAX));
        vector<Node*>nodes(N);
        for(int i = 0; i < N; i++) {
            nodes[i] = new Node();
        }
        vector<bool>visited(N, false);

        int u, v;
        for(vector<int>path : edges) {
        	u = path[0]; v = path[1];
        	nodes[u]->child.push_back(v);
        	nodes[v]->child.push_back(u);
        }

        vector<int>pathnodes;
        for(int i = 0; i < N; i++) {
            traverse(i, nodes, visited, matrix, pathnodes);
        }
        
        vector<int>result(N);
        int res;
        for(int i = 0; i < N; i++) {
            res = 0;
            for(int j = 0; j < N; j++) {
                if(i != j) //printf(" 0");
                // else {
                //     printf(" %d", matrix[i][j]);
                    res += matrix[i][j];
                // }
            }
            // printf("\n");
            result[i] = res;
        }
        
        return result;
    }

    void traverse(int source, vector<Node*>& nodes, vector<bool>& visited,
    		vector<vector<int>>& matrix, vector<int>& pathnodes) {
        
//         printf("%d : ", source);
//         for(int x : pathnodes) {
//             printf("%d ", x);
//         }
//         printf("\n");
        
        int dist = 2;
        for(int i = pathnodes.size()-2; i >= 0; i--) {
            matrix[pathnodes[i]][source] = matrix[source][pathnodes[i]] = dist++;
        }
        
    	visited[source] = true;
        pathnodes.push_back(source);
        for(int i = 0; i < nodes[source]->child.size(); i++) {
    		int u = source;
    		int v = nodes[source]->child[i];
            
            if(!visited[v]) {
                matrix[u][v] = matrix[v][u] = 1;
                traverse(v, nodes, visited, matrix, pathnodes);
            }
    	}
        visited[source] = false;
        pathnodes.pop_back();
        
    	return;
    }
};
