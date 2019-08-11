#include <bits/stdc++.h>
using namespace std;

// Prim's Algorithm for Minimum Spanning Tree

struct Node {
	int id;
	vector<pair<int,int>>edge;
	Node(int id) : id(id) {}
};

struct Pair
{
	int weightEdge;
	int index;

	bool operator<(const Pair& other) const {
		return weightEdge > other.weightEdge;
	}
};

long long int primAlgorithm(vector<Node*>nodes, int start, int N)
{
	priority_queue<Pair>pq;

	vector<int>visited(N+1, 0);
	long long int minimumCost = 0;

	Pair curr;
	int end;

	pq.push({0, start});

	while(!pq.empty()) {
		curr = pq.top(); // select edge with minimum weight
		pq.pop();

		start = curr.index;
		if(visited[start] == 1)
			continue;

		minimumCost += curr.weightEdge;
		visited[start] = 1;

		for(int i = 0; i < nodes[start]->edge.size(); i++) {
			pair<int,int> y = nodes[start]->edge[i];
			if(visited[y.second] == 0) { // next node
				pq.push({y.first, y.second});
			}
		}
	}

	return minimumCost;
}

// Utility Program:
int main() {

	int N, M, U, V, type, X;

	cin >> N >> M;

	vector<Node*>nodes(N+1);
	for(int i = 1; i <= N; i++) {
		nodes[i] = new Node(i);
	}

	for(int i = 0; i < M; i++) {
		cin >> U >> V;
		cin >> type;
		switch(type) {
			case 0:	X = 0;
					break;
			case 1: cin >> X;
		}
		nodes[U]->edge.push_back(make_pair(X, V));
		nodes[V]->edge.push_back(make_pair(X, U));
	}

	long long int minimumCost = primAlgorithm(nodes, 1, N);
	cout << minimumCost << endl;

	return 0;
}

/*

4 6
1 2 0
1 3 1 4
1 4 1 1
2 3 1 2
2 4 1 5
3 4 1 3

*/

