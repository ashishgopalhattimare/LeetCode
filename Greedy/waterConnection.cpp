#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int diameter;
    vector<pair<int, int> >V;
};

int source, destination, minimum;

void DFS(Node *house, int source, bool *visited)
{
    visited[source] = true;
    
    ::destination = source;
    
    for(int i = 0; i < house[source].V.size(); i++) {
        if(!visited[house[source].V[i].first]) {
            ::minimum = min(::minimum, house[source].V[i].second);
            
            DFS(house, house[source].V[i].first, visited);
        } 
    }
    
    visited[source] = false;
    return;
}

int main(int argc, char* argv[])
{
    int t;
    int n, p;
    int a, b, d;
    
    cin >> t;
    while(t--) {
        cin >> n >> p;
        
        Node *house = new Node[n];
        
        for(int i = 0; i < p; i++) {
            cin >> a >> b >> d;
            
            house[a-1].V.push_back(make_pair(b-1, d));
        }
        
        bool *visited = new bool[n];
        for(int i = 0; i < n; i++) {
            visited[i] = false;
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                ::source = i;
                ::destination = i;
                ::minimum = INT_MAX;
                DFS(house, i, visited);
                
                if(::source != ::destination) {
                    printf("%d %d %d\n", ::source + 1, ::destination + 1, ::minimum);
                }
            }
        }
    }

    return 0;
}