// https://leetcode.com/problems/univalued-binary-tree/description/

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
    
    bool traverse(TreeNode *head, int val) {
        if(head == NULL) return true;
        
        if(head->val != val) return false;
        
        return traverse(head->left, val) && traverse(head->right, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        
        if(root == NULL) return true;
        
        return traverse(root, root->val);
    }
};
