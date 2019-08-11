// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Medium

struct Node {
    int id;
    bool mst;
    int cost;
    vector<vector<int>>neighbour; // <next node, cost>
    
    Node(int id) : id(id) {
        cost = INT_MAX;
        mst = false;
    }
};

struct Data {
    int id, cost, k;
    
    bool operator<(const Data& other) const {
        return cost > other.cost;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<Node*>nodes(n);
        for(int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        
        for(vector<int> x : flights) {
            nodes[x[0]]->neighbour.push_back({x[1], x[2]});
        }
        
        // for(int i = 0; i < n; i++) {
        //     printf("%d : ", nodes[i]->id);
        //     for(int j = 0; j < nodes[i]->neighbour.size(); j++) {
        //         printf("[%d,%d] ", nodes[i]->neighbour[j][0], nodes[i]->neighbour[j][1]);
        //     }
        //     printf("\n");
        // }
        
        K = K + 1; // number of edges to cover from src to destination
        
        priority_queue<Data>pq;
        Data curr;
        vector<int> index;
        
        nodes[src]->cost = 0;
        pq.push({src, nodes[src]->cost, 0});
        
        while(!pq.empty()) {
            
            curr = pq.top();
            pq.pop();
            nodes[curr.id]->mst = true;
            
            for(int i = 0; i < nodes[curr.id]->neighbour.size(); i++) {
                index = nodes[curr.id]->neighbour[i];
                
                if(nodes[index[0]]->mst == false && curr.k + 1 <= K) {
                    nodes[index[0]]->cost = min(nodes[index[0]]->cost, curr.cost + index[1]);
                    
                    pq.push({index[0], curr.cost + index[1], curr.k + 1});
                }
            }
        }
        
        // for(int i = 0; i < n; i++) {
        //     printf("%d %d\n", nodes[i]->id, nodes[i]->cost);
        // }
        
        if(nodes[dst]->cost == INT_MAX) {
            return -1;
        }
        return nodes[dst]->cost;
    }
};
