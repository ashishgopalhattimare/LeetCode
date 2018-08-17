// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution {
public:
    
    struct Node
    {
        char color;
        bool visited;
        vector<int>neighbour;
        
        Node() {
            visited = false;
            color = '.';
            
            vector<int>temp;
            neighbour = temp;
        }
    };
    
    bool isBipartite(int source, vector<Node>& vertex, char this_color)
    {
        vertex[source].visited = true;
        vertex[source].color = this_color;
        
        char next_color;
        // decide the next color to color the neighbour with
        if(this_color == 'b') {
            next_color = 'g';
        } else {
            next_color = 'b';
        }
        
        char color;

        // color neighbour nodes, if possible
        for(int i = 0; i < vertex[source].neighbour.size(); i++) {
            
            // neighbour current color
            color = vertex[vertex[source].neighbour[i]].color;
            
            // if the neigbour is currently now coloured
            if(color == '.') {
                vertex[vertex[source].neighbour[i]].color = next_color;
            }
            // if the neighbour is colored with same as source color
            else if(color == this_color) {
                return false; // graph not possible to be bipartite
            }
        }
        
        // DFS node
        for(int i = 0; i < vertex[source].neighbour.size(); i++) {
            
            // is already visited
            if(vertex[vertex[source].neighbour[i]].visited) continue;
            
            // check if bipartite is still possible or not
            else if(!isBipartite(vertex[source].neighbour[i], vertex, next_color)) {
                return false;
            }
        }
        
        // possible bipartite to this graph
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        vector<Node>vertex(graph.size());
        
        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                vertex[i].neighbour.push_back(graph[i][j]);
            }
        }
        
        // the graph may contain a multiple components in a graph
        for(int i = 0; i < graph.size(); i++) {
            if(vertex[i].visited) continue;
            
            if(!isBipartite(i, vertex, 'b')) {
                return false;
            }
        }
        
        return true;
    }
};