#include <bits/stdc++.h>

using namespace std;

struct Vertex {
    int color;
    vector<int>V;
};

bool notPossible;

void coloring(Vertex *vertex, int source, const int n, const int m, bool *visited, bool *colored)
{
	// determine this node color
	for (int i = 0; i < m; i++) {
		colored[i] = false;
	}

	for(int i = 0; i < vertex[source].V.size(); i++) {
		if(vertex[vertex[source].V[i]].color == -1) continue;
		else {
			colored[vertex[vertex[source].V[i]].color] = true;
		}
	}

	for (int i = 0; i < m; i++) {
		if(colored[i] == false) {

			vertex[source].color = i;
			visited[source] = true;

			for(int j = 0; j < vertex[source].V.size(); j++) {
				if(!visited[vertex[source].V[i]]) {
					coloring(vertex, vertex[source].V[i], n, m, visited, colored);
				}
			}
			return;
		}
	}

	::notPossible = true;

	return;
}

int main(int argc, char* argv[])
{
    int t, n, e, m;
    int u, v;
    
    cin >> t;
    while(t--) {
        cin >> n >> m >> e;

        Vertex *vertex = new Vertex[n];
        
        for(int i = 0; i < e; i++) {
            cin >> u >> v;
            
            vertex[u-1].V.push_back(v-1);
            vertex[v-1].V.push_back(u-1);
        }

        if(n == m) {
        	printf("1\n");
        	continue;
        }
        
        bool *visited = new bool[n];
        bool *colored = new bool[m];

        for (int i = 0; i < n; i++) {
        	visited[i] = false;
        	colored[i] = false;
        	vertex[i].color=-1;
        }

        ::notPossible = false;
        for (int i = 0; i < n; i++) {
        	if(!visited[i]) {
        		coloring(vertex, i, n, m, visited, colored);
        	}
        }

        if(::notPossible) {
        	printf("0\n");
        }
        else {
        	printf("1\n");
        }
    }
    

    return 0;
}