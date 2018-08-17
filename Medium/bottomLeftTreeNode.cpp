// https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
    
    int value;
    int depth;
    
    void inorder(TreeNode *root, int deep)
    {
        if(root == NULL) return;
        
        if(depth < deep) {
            value = root->val;
            depth = deep;
        }
        
        inorder(root->left, deep + 1);
        inorder(root->right, deep + 1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        
        depth == INT_MIN;
        value = root->val; // resolve error when only head / set it by default to first node
        inorder(root, 0);
        
        return value;
    }
};