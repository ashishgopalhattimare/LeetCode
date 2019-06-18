// https://www.geeksforgeeks.org/count-nodes-within-k-distance-from-all-nodes-in-a-set/

#include<bits/stdc++.h>
#include <fstream>

using namespace std;

#define MARKED_NODE true
int genesis;

struct Node {
	int id, reachable;
	bool primary, visited;
	vector<int>neighbour;

	Node(int id) : id(id) {
		primary = reachable = 0;
		visited = false;
	}
};

void DFS(int source, vector<Node*> nodes, int distance, int k) {

	if(nodes[source]->visited || distance > k) return;

	if(source != genesis) nodes[source]->reachable++;
	nodes[source]->visited = 1;

	int index;
	for(int i = 0; i < nodes[source]->neighbour.size(); i++) {
		index = nodes[source]->neighbour[i];
		if(!nodes[index]->visited) {
			DFS(index, nodes, distance + 1, k);
		}
	}
	nodes[source]->visited = 0;
}

int main()
{
	int n, m, u, v, k, s;
	cin >> n >> m >> k;

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		nodes[i] = new Node(i);
	}

	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		nodes[u]->neighbour.push_back(v);
		nodes[v]->neighbour.push_back(u);
	}

	// Marked Node from where distance is to be taken into consideration
	cin >> s;
	for(int i = 0; i < s; i++) {
		cin >> u;
		nodes[u]->primary = MARKED_NODE;
	}

	vector<bool>visited(n+1, false);
	for(int i = 1; i <= n; i++) {
		if(nodes[i]->primary == MARKED_NODE) {
			genesis = i;
			DFS(i, nodes, 0, k);
		}
	}

	printf("Nodes with index\n");
	for(int i = 1; i <= n; i++) {
		if(!nodes[i]->primary && nodes[i]->reachable == s) {
			printf("%d ", i);
		}
	}
	printf("\nhave distance less than %d from the marked nodes\n", s);

	return 0;
}

/**

10 9 3
1 2
1 9
1 4
4 3
4 7
4 8
4 6
6 5
6 10
3
2 3 5

 */

