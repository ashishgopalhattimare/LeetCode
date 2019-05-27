// Mock Test

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
    
    bool inRange(int x, int l, int r) {
        return x >= l && x <= r;    
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL) return NULL;
        
        root->left = trimBST(root->left, L, R);		// update left subtree
        root->right = trimBST(root->right, L, R);	// update right subtree
        
        if(inRange(root->val, L, R)) return root;	// if root in range return root

        return (root->left) ? root->left : root->right; // if left exists return left, else right
    }
};
