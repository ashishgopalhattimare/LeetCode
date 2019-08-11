#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    int uniqueCode;
    vector<int>edges;

    Node(int id) : id(id), uniqueCode(0) {

    }
};

void permutation(vector<vector<int>>&matrix, int source)
{
    if(source == matrix.size()) {
        for(vector<int> x : matrix) {
            for(int i : x) printf("%d ", i);
        }
        printf("\n");
        return;
    }
    sort(matrix[source].begin(), matrix[source].end());

    bool nextValid;
    do {
        permutation(matrix, source+1);
        nextValid = next_permutation(matrix[source].begin(), matrix[source].end());
    }while(nextValid);
}

int main()
{
    int n = 6;
    vector<Node*>nodes(n+1);
    for(int i = 1; i <= n; i++) {
        nodes[i] = new Node(i-1);
    }

    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{3,4},{2,5},{3,6},{4,5},{4,6}};
    for(vector<int> x : edges) {
        nodes[x[0]]->edges.push_back(x[1]);
    }

    // Assign Unique code;
    list<int>ll;
    int curr;

    ll.push_back(1);

    int id = 1, size, index;
    while(!ll.empty()) {
        
        size = ll.size();
        while(size--) {
            curr = ll.front();
            ll.pop_front();

            nodes[curr]->uniqueCode = id;

            for(int i = 0; i < nodes[curr]->edges.size(); i++) {
                index = nodes[curr]->edges[i];
                ll.push_back(index);
            }
        }
        id++;
    }

    vector<vector<int>>matrix(id);
    
    for(int i = 1; i <= n; i++) {
        matrix[nodes[i]->uniqueCode].push_back(nodes[i]->id);
    }

    permutation(matrix, 1);

    return 0;
}