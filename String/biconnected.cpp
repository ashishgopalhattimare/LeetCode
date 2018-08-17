#include <bits/stdc++.h> 
#include <unordered_map> 
#include <map>
#include <iostream> 
#include <vector> 
#include <algorithm>
#include <cstdlib> 
#include <cstdio> 
#include <string>
#include <stack> 
#include <deque> 
#include <queue>
#include <cctype> 
#include <cmath> 


using namespace std;

struct Vertex
{
    int data;
    vector<int>V;
};

bool biconnect;

bool DFS(Vertex *vertex, int source, int time, bool *visited, int *lowTime)
{
    visited[source] = true;
    lowTime[source] = time;
    
    for(int i = 0; i < vertex[source].V.size(); i++) {
        if(!visited[vertex[source].V[i]]) {
            
            DFS(vertex, vertex[source].V[i], time+1, visited, lowTime));

            if()

        }
    }
}

void Biconnected(Vertex *vertex, int v)
{
    bool *visited = new bool[v];
    int *lowTime = new int[v];
    
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    
    ::biconnect = true;
    DFS(vertex, 2, 0, visited, lowTime);
    
    if(::biconnect) {
        printf(" ->1\n");
    }
    else {
        printf(" ->0\n");
    }
    
    return;
}

int main(int argc, char* argv[])
{
    int t;
    int v, e;
    int count;
    int u1, u2;
    bool biconnected;
    
    cin >> t;
    
    while(t--) {
        cin >> v >> e;
        
        Vertex *vertex = new Vertex[v];
        for(int i = 0; i < v; i++) {
            vertex[i].data = i;
        }
        
        while(e--) {
            cin >> u1 >> u2;
            vertex[u1].V.push_back(u2);
            vertex[u2].V.push_back(u1);
        }
        
        Biconnected(vertex, v);
    }

    return 0;
}