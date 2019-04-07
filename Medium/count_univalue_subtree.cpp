/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode *head, int *count)
{
	// leaf node of the tree
	if(head->left == NULL && head->right == NULL) {
		(*count)++;
		return head->val;
	}

	int l, r; // value from left and right subtree

	if(head->left) { // left node is present
		l =  dfs(head->left, count);
	}
	if(head->right) { // right node is present
		r = dfs(head->right, count);
	}

	if(head->left && head->right) { // if both the nodes are present
		if(head->val == l && head->val == r) {
			(*count)++;
			return head->val;
		}
	}
	else if(head->left) { // if only left node is present
		if(head->val == l) {
			(*count)++;
			return head->val;
		}
	}
	else {
		if(head->val == r) { // if only right node is present
			(*count)++;
			return head->val;
		}
	}

	// this subtree is not a univalue subtree
	return -1;
}

int countUnivalueSubtree(TreeNode *root)
{
	if(root == NULL) return 0;

	int count = 0;
	int tempValue = dfs(root, &count);

	return count;
}
/*
        //         5
        //        / \
        //       1   5
        //      / \   \
        //     5   5   5
		//    / \   \   \
		//   5   5   4   1
		            / \   \
		//         4   4   1

        // result = 8
*/