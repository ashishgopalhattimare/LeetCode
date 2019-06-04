// https://leetcode.com/problems/delete-node-in-a-bst/
// Revisted

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(root->val == key) {
            if(root->left && root->right) { // both child exists
                TreeNode *ptr = root->right; // go to smallest node right to the deleting node to replace it
                TreeNode *prev;
                
                while(ptr) ptr = (prev=ptr)->left;
                
                root->val = prev->val;
                root->right = deleteNode(root->right, prev->val);
                
                return root;
            }
            return (root->left) ? root->left : root->right;
        }
        
        root->right = deleteNode(root->right, key);
        root->left = deleteNode(root->left, key);
        
        return root;
    }
};
