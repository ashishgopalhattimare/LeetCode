/**

You are given a tree of n vertices. A tree with n vertices is an undirected connected graph with n−1 edges. Vertices are numbered from 1 to n.
There are m nodes in the tree on which a diamond is placed. You have to find the shortest distance between any diamond pair.
Distance between a diamond pair is the distance between its nodes.

Input Format
First line contains two integers n and m, n is the number of nodes, m is the number of nodes on which diamonds are placed.
Next n - 1 lines contain two integers u and v, denoting an edge between node u and node v.
Last line contains m integers, nodes on which diamonds are placed.

Constraints
2 ≤ m ≤ n ≤ 106

**/

#include <bits/stdc++.h>
using namespace std;

static int INF = 2500000;
static int diamondPath = INF;

struct TreeNode {
    int val;
    int parent;
    bool isDiamonds, visited;
    vector<int>edge;
    
    TreeNode(int val) : val(val) {
        isDiamonds = false;
        visited = false;
        
        parent = -1;
    }
};

int traversalTree(unordered_map<int, TreeNode*>& mapi, int source)
{
    mapi[source]->visited = true;
    
    int short1 = INF, short2 = INF;
    int pathlen;
    
    for(int i = 0; i < mapi[source]->edge.size(); i++) {
        int next = mapi[source]->edge[i];
        
        if(mapi[next]->visited == false) {
            pathlen = traversalTree(mapi, next);
            
            vector<int>arr = {pathlen, short1, short2};
            sort(arr.begin(), arr.end());
            
            short1 = arr[0];
            short2 = arr[1];
        }
    }
    
    if(mapi[source]->isDiamonds == false) { // might be between neighbours
        
        if(short1 < INF && short2 < INF) { // both are some sort of diamond path
            
            diamondPath = min(diamondPath, short1 + short2);
            return min(short1, short2) + 1;
        }
        else if(short1 < INF) return short1 + 1;
        else if(short2 < INF) return short2 + 1;
        
        // printf("%d returns %d\n", source, INF);
        return INF;
    }
    
    // If here, then the node is diamond node
    diamondPath = min(diamondPath, min(short1, short2));
    
    // printf("%d returns %d\n", source, 1);
    return 1; // this is diamond node
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    int u, v, k;
    
    cin >> n >> m;
    
    unordered_map<int, TreeNode*> mapi;
    
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        
        if(mapi.find(u) == mapi.end()) {
            mapi[u] = new TreeNode(u);
        }
        if(mapi.find(v) == mapi.end()) {
            mapi[v] = new TreeNode(v);
        }
        
        k = u;
        
        mapi[u]->edge.push_back(v);
        mapi[v]->edge.push_back(u);
        
        mapi[v]->parent = u;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> u;
        mapi[u]->isDiamonds = true;
    }
    
    // for(auto itr = mapi.begin(); itr != mapi.end(); itr++) {
    //     if(itr->second->parent == -1) {
    //         traversalTree(mapi, itr->first);
    //     }
    // }
    
    traversalTree(mapi, k);
    
    cout << diamondPath << endl;
    
    return 0;
}

/**
11 2
11 2
11 3
11 4
2 5
2 6
3 7
3 8
4 9
5 10
6 1
1 2
**/