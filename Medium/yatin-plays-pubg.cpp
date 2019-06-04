// https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/dummy3-4/
// Height of the Tree

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {}

	TreeNode* insertNode(TreeNode *head, int val);
	int maxLevel(TreeNode *head);
};

int TreeNode::maxLevel(TreeNode *head)
{
	if(head == NULL) return 0;
	return max(maxLevel(head->left) , maxLevel(head->right)) + 1;
}

TreeNode *TreeNode::insertNode(TreeNode *head, int val)
{
	if(head == NULL) return new TreeNode(val);

	if(val < head->val) {
		head->left = insertNode(head->left, val);
	}
	else {
		head->right = insertNode(head->right, val);
	}
	return head;
}

int main()
{
	int t;
	cin >> t;

	while(t--) {
		int n, d;
		cin >> n;

		TreeNode *root;

		cin >> d;
		root = new TreeNode(d);
		for(int i = 1; i != n; i++) {
			cin >> d;
			root->insertNode(root, d);
		}
		cout << root->maxLevel(root) << endl;
	}
	return 0;
}

