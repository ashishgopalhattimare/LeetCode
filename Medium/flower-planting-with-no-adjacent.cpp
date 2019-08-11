// https://leetcode.com/problems/flower-planting-with-no-adjacent/
// Easy
// Graph, Coloring with n colors

struct Garden
{
    int color;
    bool visited, l;
    vector<int>neighbour;
    
    Garden() : color(-1), visited(false), l(false) {}
};

class Solution {
public:
    
    void countNodes(int source, vector<Garden*>& garden, int& maximNodes)
    {
        garden[source]->l = true;
        maximNodes++;
        
        for(int i = 0; i < garden[source]->neighbour.size(); i++) {
            int v = garden[source]->neighbour[i];
            
            if(garden[v]->l == false) {
                countNodes(v, garden, maximNodes);
            }
        }
        return;
    }
    
    bool graphTraversal(int source, vector<Garden*>& garden, int colors, int maxim, int curr, int N)
    {
        garden[source]->visited = true; // make this node visited
        
        bool colorTaken[colors] = {false};
        
        // realise which colors are taken
        for(int i = 0; i < garden[source]->neighbour.size(); i++) {
            int v = garden[source]->neighbour[i];
            
            if(garden[v]->color != -1) { // if the color is there, make it colored
                colorTaken[garden[v]->color] = true;
            }
        }
        
        for(int color = 0; color < colors; color++) {
            
            if(colorTaken[color]) continue;
            
            garden[source]->color = color;
            if(maxim == curr+1) { // this is the last node to be colored
                return true;
            }
            else {
                
                bool nochild = true; // if no child present
                bool valid = true; // all branches are valid
                for(int i = 0; i < garden[source]->neighbour.size(); i++) {
                    int v = garden[source]->neighbour[i];
                    
                    if(!garden[v]->visited) {
                        nochild = false; // there are child present
                        valid = valid | graphTraversal(v, garden, colors, maxim, curr+1, N); // all branches are valid
                    }
                }
                if(nochild) return true; // only child, then true
                return valid; // if any branch return false, this becomes false
            }
        }
        
        garden[source]->visited = false;
        garden[source]->color = -1;
        return false;
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        
        vector<Garden*>garden(N+1);
        
        for(int i = 0; i <= N; i++) {
            garden[i] = new Garden();
        }
        
        int u, v;
        for(int i = 0; i < paths.size(); i++) {
            u = paths[i][0];
            v = paths[i][1];
            
            garden[u]->neighbour.push_back(v);
            garden[v]->neighbour.push_back(u);
        }
        
        for(int i = 1; i <= N; i++) {
            sort(garden[i]->neighbour.begin(), garden[i]->neighbour.end());
        }
        
        int maximNode;
        for(int i = 1; i <= N; i++) {
            if(!garden[i]->visited) {
                maximNode = 0;
                countNodes(i, garden, maximNode);
                graphTraversal(i, garden, 4, maximNode, 0, N);
            }
        }
        
        vector<int>result(N);
        for(int i = 1; i <= N; i++) {
            result[i-1] = garden[i]->color+1;
        }
        return result;
    }
};
