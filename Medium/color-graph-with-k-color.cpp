#include<bits/stdc++.h>
#include <fstream>

using namespace std;

#define NOT_CHOSEN false
#define CHOSEN true

int totalTaken = 0;

struct Node {
	int id, color;
	bool visited;
	vector<int>neighbour;

	Node(int id) : id(id), color(-1) {
		visited = false;
	}
};

bool colorGraph(int source, vector<Node*>& nodes, int k) {

	vector<bool>colorChose(k, false);
	nodes[source]->visited = true;

	int index;
	for(int i = 0; i < nodes[source]->neighbour.size(); i++) { // Check which colors are taken
		index = nodes[source]->neighbour[i];
		if(nodes[index]->color != -1) {
			colorChose[nodes[index]->color] = CHOSEN; // this color is taken
		}
	}

	bool possible;
	for(int i = 0; i < k; i++) {
		if(colorChose[i] == NOT_CHOSEN) {
			nodes[source]->color = i;

			totalTaken++;
			if(totalTaken == nodes.size()-1) { // if all the nodes are filled with valid colors
				cout << "FINISHED SUCCESSFULLY" << endl;
				return true;
			}

			for(int j = 0; j < nodes[source]->neighbour.size(); j++) {
				index = nodes[source]->neighbour[j];
				if(!nodes[index]->visited) {
					possible = colorGraph(index, nodes, k);

					if(possible) return true;
				}
			}
		}
	}

	nodes[source]->visited = false;
	nodes[source]->color = -1;
	totalTaken--;

	return false;
}

int main()
{
	ifstream infile;
	infile.open("input.txt");

	printf("Coloring of a graph with k different Colors\n\n");

	int n, k, m, u, v;
	cin >> n >> m >> k;

	vector<Node*>nodes(n+1); // n nodes in the graph
	for(int i = 0; i <= n; i++)
		nodes[i+1] = new Node(i+1);

	for(int i = 0; i < m; i++) { // edges between the nodes (undirected)
		cin >> u >> v; // u - source, v - destination

		nodes[u]->neighbour.push_back(v);
		nodes[v]->neighbour.push_back(u);
	}

	// k - different I need to color with
	if(colorGraph(1, nodes, k)) {
		for(int i = 1; i <= n; i++) {
			cout << nodes[i]->id << " " << nodes[i]->color + 1 << endl;
		}
	}
	else {
		cout << "COLOR GRAPH WITH K COLOR NOT POSSIBLE" << endl;
	}

	return 0;
}

/**

5 8 3
1 2
1 3
1 4
2 4
2 3
3 4
3 5
4 5

 */
