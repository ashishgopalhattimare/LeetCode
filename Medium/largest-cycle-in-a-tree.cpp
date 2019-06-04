// https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/approximate/largest-cycle-in-a-tree-9113b3ab/

// Wrong Answer O(n)

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node *parent, *left, *right;

	Node(int val) : val(val), parent(NULL), left(NULL), right(NULL) {}
};

static pair<Node*, Node*> maximNodes;
static int maximDiameter;

pair<Node*, int> LargestPath(Node *head) {

	if(head == NULL) return make_pair(head, 0);

	if(head->left == NULL && head->right == NULL) {
		return make_pair(head, 1);
	}
	
    pair<Node*, int> left, right;
    
    if(head->left)  left = LargestPath(head->left);
    if(head->right) right = LargestPath(head->right);

    // both left and right child are present
    if(head->left && head->right) {
        if(maximDiameter < left.second + right.second + 1) {
    		maximNodes.second = right.first;
    		maximNodes.first = left.first;
    
    		maximDiameter = left.second + right.second + 1;
    	}
    
    	if(left.second > right.second) {
    		return make_pair(left.first, left.second+1);
    	}
    	return make_pair(right.first, right.second+1);
    }
    
    else if(head->left) {
        if(maximDiameter < left.second + 1) {
            maximNodes.first = left.first;
            maximNodes.second = head;
            
            maximDiameter = left.second + 1;
        }
        return make_pair(left.first, left.second+1);
    }
    
    if(maximDiameter < right.second + 1) {
        maximNodes.second = right.first;
        maximNodes.first = head;
        
        maximDiameter = right.second + 1;
    }
    return make_pair(right.first, right.second+1);
}

int main()
{
	int n;
	cin >> n;

	vector<Node*>nodes(n+1);
	for(int i = 1; i <= n; i++) {
		nodes[i] = new Node(i);
	}

	int u, v;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		
		nodes[v]->parent = nodes[u];

		if(nodes[u]->left == NULL) {
			nodes[u]->left = nodes[v];
		}
		else {
			nodes[u]->right = nodes[v];
		}
	}

	maximDiameter = -1;
	
	for(int i = 1; i <= n; i++) {
		if(nodes[i]->parent == NULL) {
			pair<Node*, int> diameter = LargestPath(nodes[i]);
			cout << maximNodes.first->val << " " << maximNodes.second->val << endl;
			
			break;
		}
	}

	return 0;
}

//12
//1 2
//2 3
//3 4
//4 5
//4 6
//3 7
//7 8
//8 9
//9 10
//10 11
//11 12

