// https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/
// Complexity : O(V+E)
// undirected : O(V*(V+E))

#include<bits/stdc++.h>

using namespace std;

struct Node {
	int id, maxLength;
	bool visited;
	vector<pair<int,int>>child;
	Node(int id) : id(id) {
		visited = false;
		maxLength = INT_MIN;
	}
};

void longestPathDirectedAcyclicGraph(vector<Node*>& nodes) {

	int source, length;

	nodes[1]->maxLength = 0;

	list<pair<int,int>>ll;
	pair<int,int>ptr;

	ll.push_back({1, 0});
	while(!ll.empty()) {
		ptr = ll.front();
		ll.pop_front();

		// Extract Data
		source = ptr.first; length = ptr.second;

		// Determine new Max Length from the source node
		nodes[source]->maxLength = max(nodes[source]->maxLength, length);

		for(int i = 0; i < nodes[source]->child.size(); i++) {
			pair<int,int>node = nodes[source]->child[i];

			ll.push_back(make_pair(node.first, nodes[source]->maxLength + node.second));
		}
	}
	return;
}

int main()
{
	int n, m;

	n = 6; 	// number of nodes
	m = 10; // weight of each node

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		nodes[i] = new Node(i);
	}

	int edges[][3] ={{1,2,5}, {2,3,2}, {3,4,7}, {4,5,-1}, {5,6,-2},
					{2,4,6}, {4,6,1}, {1,3,3}, {3,5,4}, {3,6,2}};

	// filling edges in the graph (undirected graph)
	for(int i = 0; i < m; i++) {
		nodes[edges[i][0]]->child.push_back(make_pair(edges[i][1], edges[i][2]));
	}
	longestPathDirectedAcyclicGraph(nodes);

	for(int i = 1; i <= n; i++) {
		printf("id : %d, longestPath : %d\n", i, nodes[i]->maxLength);
	}

	return 0;
}

