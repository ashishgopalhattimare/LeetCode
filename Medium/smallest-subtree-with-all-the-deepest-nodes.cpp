// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Medium, Facebook

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
    int maxDepth;
    void inorder(TreeNode *root, int level) {
        if(root == NULL) return;
        
        maxDepth = max(maxDepth, level);
        
        inorder(root->right, level+1);
        inorder(root->left, level+1);
    }
    
    TreeNode *deepest(TreeNode *root, int level) {
        // not found
        if(root == NULL) return NULL;
        
        // return node at maximum Depth, current result
        if(maxDepth == level) return root;
        
        TreeNode *right = deepest(root->right, level+1);
        TreeNode *left = deepest(root->left, level+1);
        
        // If both the subtree has deepest node, root is the new result
        if(left && right) return root;

        // else, return whichever has the deepest node
        return (left) ? left : right;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        // Find the maximum Depth in the tree
        maxDepth = 0;
        inorder(root, 1);
        
        return deepest(root, 1);
    }
};