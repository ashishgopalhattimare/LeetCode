// https://leetcode.com/problems/convert-bst-to-greater-tree/
// Easy

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
    
    int sumTotal = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        
        if(root == NULL) return root;
        
        root->right = convertBST(root->right);
        
        int val = root->val;
        root->val += sumTotal;
        sumTotal += val;
        
        root->left = convertBST(root->left);
        
        return root;
    }
};