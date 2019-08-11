#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    bool good, mst;
    int cost;
    vector<vector<int>>neighbour; // next node, cost edge

    Node(int id) : id(id), good(false) {
        cost = INT_MAX;
        mst = false;
    }
};

struct Detail {
    int src, temp, cost;
    bool operator<(const Detail& other) const {
        return cost > other.cost;
    }
};

void algorithm(vector<Node*>& nodes, int source)
{
    int tempSource = source;

    priority_queue<Detail>pq;
    Detail curr;

    vector<int>index;

    pq.push({source, -1, -1});
    int counter = 0;
    while(!pq.empty()) {

        curr = pq.top();
        pq.pop();

        if(curr.temp != -1) {
            nodes[curr.src]->mst = true;
        }

        if(curr.src != curr.temp) {
            if(nodes[curr.src]->good && nodes[curr.temp]->good) {
                nodes[curr.src]->cost = min(nodes[curr.src]->cost, curr.cost);
                nodes[curr.temp]->cost = min(nodes[curr.temp]->cost, curr.cost);
            }
        }

        for(int i = 0; i < nodes[curr.temp]->neighbour.size(); i++) {
            index = nodes[curr.temp]->neighbour[i];
            
            if(nodes[curr.temp]->good) {
                pq.push({curr.temp, index[0], index[1]});
                printf("push : %d %d %d\n", curr.temp, index[0], index[1]);
            }
            else {
                if(curr.src != index[0]) {
                    pq.push({curr.src, index[0], curr.cost + index[1]});
                    printf("PUSH : %d %d %d\n", curr.src, index[0], curr.cost + index[1]);
                }
            }
        }
        
        counter++;
        if(counter == 10) break;
    }

    for(int i = 1; i < nodes.size(); i++) {
        printf("%d : %d\n", nodes[i]->id, nodes[i]->cost);
    }
}

int main()
{
    int n = 5;
    vector<Node*>nodes(n+1);
    for(int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    vector<vector<int>>edges = {{1,2,3},{2,3,4},{3,4,1},{4,5,8},{5,1,19}};
    for(vector<int> x : edges) {
        nodes[x[0]]->neighbour.push_back({x[1],x[2]});
        nodes[x[1]]->neighbour.push_back({x[0],x[2]});
    }

    vector<int>goodNodes = {1,3,5};
    for(int x : goodNodes) {
        nodes[x]->good = true;
    }

    algorithm(nodes, 1);

    return 0;
}