// https://www.geeksforgeeks.org/roots-tree-gives-minimum-height/

#include<bits/stdc++.h>

using namespace std;

struct Node {
	int id;
	bool visited;
	vector<int>child;
	Node(int id) : id(id) {
		visited = false;
	}
};

void minimumHeight(vector<Node*>& nodes) {

	if(nodes.size() == 0) return;

	list<pair<int,int>>ll; // node and level pair list
	vector<int>result;

	int n = nodes.size();
	int remaining = n-1;

	for(int i = 1; i < n; i++) {
		if(nodes[i]->child.size() == 1) { // leaf node
			ll.push_back(make_pair(i, 1));
			nodes[i]->visited = true;
			remaining--;
		}
	}

	int maximLevel = 1;
	pair<int,int> curr;

	while(remaining) {
		curr = ll.front();
		// neighbors of current node which are not visited
		for(int i = 0; i < nodes[curr.first]->child.size() && remaining; i++) {
			int index = nodes[curr.first]->child[i];
			if(!nodes[index]->visited) {
				ll.push_back(make_pair(index, curr.second+1));
				maximLevel = max(maximLevel, curr.second+1);

				nodes[index]->visited = true;
				remaining--;
			}
		}
		ll.pop_front();
	}

	while(!ll.empty()) {
		if(ll.front().second == maximLevel){
			cout << ll.front().first << " ";
		}
		ll.pop_front();
	}
	return;
}

int main()
{
	int n, m;

	n = 5; 	// number of nodes
	m = n-1;// weight of each node

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		nodes[i] = new Node(i);
	}

	int edges[][2] = {{1, 3}, {3, 2}, {3, 4}, {4, 5}};

	// filling edges in the graph (undirected graph)
	for(int i = 0; i < m; i++) {
		nodes[edges[i][0]]->child.push_back(edges[i][1]);
		nodes[edges[i][1]]->child.push_back(edges[i][0]);
	}

	minimumHeight(nodes);

	return 0;
}

