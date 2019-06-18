// https://www.geeksforgeeks.org/delete-edge-minimize-subtree-sum-difference/

// C++ program to minimize subtree sum
// difference by one edge deletion
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

struct Node {
	int id, weight;
	bool visited;
	vector<int>child;
	Node(int id, int w) : id(id), weight(w) {
		visited = false;
	}
};

int sumTree(int source, vector<Node*>& nodes) {
	if(nodes[source]->visited) return 0;

	int sumtree = nodes[source]->weight;
	nodes[source]->visited = true;

	int index;
	for(int i = 0; i < nodes[source]->child.size(); i++) {
		index = nodes[source]->child[i];
		if(!nodes[index]->visited) {
			sumtree += sumTree(index, nodes);
		}
	}
	nodes[source]->visited = false;
	return sumtree;
}

int algorithm(int source, int parent, vector<Node*>& nodes, int *result, int total)
{
	int subtree = nodes[source]->weight;
	nodes[source]->visited = true;

	for(int i = 0; i < nodes[source]->child.size(); i++) {
		int index = nodes[source]->child[i];

		if(!nodes[index]->visited) {
			subtree += algorithm(index, source, nodes, result, total);
		}
	}

	if(parent != -1) {
		*result = min(*result, abs(total - 2*subtree));
	}
	return subtree;
}

int minimumSubtreeDifference(vector<Node*> nodes)
{
	// Get the sum of all nodes in a tree
	int totalSum = sumTree(1, nodes);

	int minDifference = INT_MAX;

	int rootNode = 1;
	int temp = algorithm(rootNode, -1, nodes, &minDifference, totalSum);

	return minDifference;
}

int main()
{
	int n, m, u, v, w;
	cin >> n >> m;

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> w;
		nodes[i] = new Node(i, w);
	}

	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		nodes[u]->child.push_back(v);
		nodes[v]->child.push_back(u);
	}

	cout << minimumSubtreeDifference(nodes) << endl;

	return 0;
}

/**

7 6
4 2 1 6 3 5 2
1 2
1 3
1 4
3 5
3 6
4 7

**/

