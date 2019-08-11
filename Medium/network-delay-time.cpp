// https://leetcode.com/problems/network-delay-time/
// Medium
// O(n^2) --> O(ElogV) using binary heap (not done though)

struct Node {
    int id, path;
    bool visited;
    vector<vector<int>>neighbour; // v, w
    
    Node(int id) : id(id), visited(false) {
        path = INT_MAX;
    }
};

void DijkstraAlgorithm(vector<Node*>& nodes, int source, int N)
{
    nodes[source]->path = 0; // shortest path to source node
    int currShortest;
    
    while(source) // while list is not empty
    {
        // I have the node with shortest path so far
        for(int i = 0; i < nodes[source]->neighbour.size(); i++) {
            auto detail = nodes[source]->neighbour[i];
            
            // Update shortest path if greater
            if(nodes[detail[0]]->visited == false) {
                nodes[detail[0]]->path = min(nodes[detail[0]]->path, nodes[source]->path + detail[1]);
            }
        }
        
        nodes[source]->visited = true;
        currShortest = INT_MAX;
        source = 0;
        
        // O(n) to find the next node
        for(int i = 1; i <= N; i++) {
            if(nodes[i]->visited == false) {
                if(currShortest > nodes[i]->path) {
                    currShortest = nodes[i]->path;
                    source = i;
                }
            }
        }
    }
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<Node*>nodes(N+1);
        for(int i = 1; i <= N; i++) {
            nodes[i] = new Node(i);
        }
        
        for(vector<int> x : times) {
            nodes[x[0]]->neighbour.push_back({x[1], x[2]});
        }
        
        DijkstraAlgorithm(nodes, K, N);
        
        int longestPath = INT_MIN;
        for(int i = 1; i <= N; i++) {
            if(nodes[i]->visited == false) {
                return -1;
            }
            longestPath = max(longestPath, nodes[i]->path);
        }
        
        return longestPath;
    }
};
