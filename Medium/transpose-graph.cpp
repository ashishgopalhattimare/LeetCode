#include<bits/stdc++.h>
#include <fstream>

using namespace std;

struct Node {
	int id;
	vector<int>neighbour;

	Node(int id) : id(id) {}
};

vector<Node*> transposeGraph(vector<Node*>& nodes) {

	int n = nodes.size();
	vector<Node*>transpose(n);
	for(int i = 1; i <= n; i++) {
		transpose[i] = new Node(i);
	}

	for(int u = 1; u <= n; u++) { // every vertex u
		for(int v : nodes[u]->neighbour) { // every neighbour vertex v
			// u --> v | v --> u
			nodes[v]->neighbour.push_back(u);
		}
	}

	return transpose;
}

int main()
{
	int n, m, u, v;
	cin >> n >> m;

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		nodes[i] = new Node(i);
	}

	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		nodes[u]->neighbour.push_back(v);
	}

	vector<Node*> transpose = transposeGraph(nodes);

	return 0;
}

