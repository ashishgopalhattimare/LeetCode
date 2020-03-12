// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(cloned == NULL) return NULL;
        
        if(cloned->val == target->val) return cloned;
        
        TreeNode *node = getTargetCopy(original, cloned->right, target);
        if(node) return node;
        
        node = getTargetCopy(original, cloned->left, target);
        return node;
    }
};