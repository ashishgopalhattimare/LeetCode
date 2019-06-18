#include<bits/stdc++.h>
#include <fstream>

using namespace std;

struct Node {
	int id;
	vector<int>neighbour;

	Node(int id) : id(id) {}
};

void DFS(int source, vector<Node*>& nodes, vector<bool>& visited, bool show = false) {

	if(show) printf("%d ", source);
	visited[source] = true;

	for(int i = 0; i < nodes[source]->neighbour.size(); i++) {
		if(!visited[nodes[source]->neighbour[i]])
			DFS(nodes[source]->neighbour[i], nodes, visited, show);
	}
	return;
}

int main()
{
	ifstream infile;
	infile.open("input.txt");

	printf("Mother Vertex of the Graph (Directed Graph) \n\n");

	int n, m, u, v;
	cin >> n >> m;

	vector<Node*>nodes(n+1); // n nodes in the graph
	for(int i = 0; i <= n; i++)
		nodes[i+1] = new Node(i+1);

	for(int i = 0; i < m; i++) { // edges between the nodes (undirected)
		cin >> u >> v; // u - source, v - destination
		nodes[u]->neighbour.push_back(v);
	}

	// Make all nodes unvisited
	vector<bool>visited(n+1, false);
	int mother = -1;

	for(int source = 1; source <= n; source++) {
		if(!visited[source]) {
			DFS(source, nodes, visited);
			mother = source;
		}
	}

	for(int i = 1; i <= n; i++) visited[i] = false;
	DFS(mother, nodes, visited);

	bool found = true;
	for(int i = 1; i <= n ; i++) {
		if(!visited[i]) found = 0;
	}

	if(found) printf("Mother Node : %d\n", mother);
	else printf("Mother Node not present\n");

	return 0;
}

/**

7 8
1 3
4 1
7 1
7 2
5 2
5 6
6 4
6 7

 */

