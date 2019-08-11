static int RED = 1, BLUE = 2;

struct Node {
    int id;
    bool self_blue, self_red;
    int inMST;

    int shortest;

    vector<vector<int>>edge; // <next,color>
    Node(int id) : id(id), shortest(INT_MAX) {
    	self_red = self_blue = false;
        inMST = 0;
    }
};

struct EdgeDetail
{
    int prevColor, distance, id;
    bool operator<(const EdgeDetail& other) const {
        return distance > other.distance;
    }
};

void primsAlgorithm(vector<Node*>& nodes, int source)
{
    priority_queue<EdgeDetail>pq;
    EdgeDetail curr;
    vector<int>index;
    
    int totalDone = 0;
    
    pq.push({-1, 0, source}); // [ prevColor, distance, source ]
    
    while(!pq.empty() && totalDone != nodes.size()) {
        
        curr = pq.top();
        pq.pop();
        
        // If the all the nodes are covered, break the loop
        if(nodes[curr.id]->shortest > curr.distance) {
            nodes[curr.id]->shortest = curr.distance;
            totalDone++;
        }
        
        // Get the current source of the node
        source = curr.id;
        
        // We assume that in worst case, the maximum times a node can be in the pq is total number of nodes, to
        // get to all the nodes
        if(nodes[source]->inMST == nodes.size()) continue;
        
        // Increase its number of times in the MST position
        nodes[source]->inMST++;
        
        for(int i = 0; i < nodes[source]->edge.size(); i++) {
            index = nodes[source]->edge[i];
            
            // Previous Color is not same as current Edge color
            if(curr.prevColor != index[1]) {
                pq.push({index[1], curr.distance+1, index[0]});
            }
            // If the are same color, check for self-edge in the current node
            else {
                if(curr.prevColor == RED && nodes[curr.id]->self_blue) { // RED->BLUE->RED
                    pq.push({RED, curr.distance+2, index[0]});
                }
                else if(curr.prevColor == BLUE && nodes[curr.id]->self_red) { // BLUE->RED->BLUE
                    pq.push({BLUE, curr.distance+2, index[0]});
                }
            }
        }
    }
    return;
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        vector<int>result(n, INT_MAX);
        vector<Node*>nodes(n);
        
        for(int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        
        // Traverse Red edges // 1
        for(vector<int> x : red_edges) {
            if(x[0] == x[1]) { // Self-Edge
                nodes[x[0]]->self_red = RED;
            }
            else nodes[x[0]]->edge.push_back({x[1], RED});
        }
        
        // Traverse Blue edges // 2
        for(vector<int> x : blue_edges) {
            if(x[0] == x[1]) { // Self-Edge
                nodes[x[0]]->self_blue = BLUE;
            }
            else nodes[x[0]]->edge.push_back({x[1], BLUE});
        }
        
        primsAlgorithm(nodes, 0);
        
        for(int i = 0; i < nodes.size(); i++) {
            if(nodes[i]->shortest == INT_MAX) {
                result[i] = -1;
            }
            else result[i] = nodes[i]->shortest;
        }
        
        return result;
    }
};
