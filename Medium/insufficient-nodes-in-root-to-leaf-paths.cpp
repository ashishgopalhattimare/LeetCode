// https://leetcode.com/contest/weekly-contest-140/problems/insufficient-nodes-in-root-to-leaf-paths/
// Medium

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	
	TreeNode* subSet(TreeNode *root, int limit, int sum) {
		if(root == NULL) return root;
		
		if(!root->left && !root->right) { // leaf node
			sum += root->val;
			return (sum >= limit) ? root : NULL;
		}
		
		bool left = subSet(root->left, limit, sum + root->val);
		if(left == false) root->left = NULL;
		
		bool right = subSet(root->right, limit, sum + root->val);
		if(right == false) root->right = NULL;
		
		return (root->left || root->right) ? root : NULL;
	}
	
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
    	return subSet(root, limit, 0);
    }
};
