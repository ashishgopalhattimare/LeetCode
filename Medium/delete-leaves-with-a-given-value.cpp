// https://leetcode.com/problems/delete-leaves-with-a-given-value/
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

    TreeNode *minValueNode(TreeNode *root) {
        TreeNode *curr = root;
        while(curr && curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }
    
    bool isLeafNode(TreeNode *root) {
        return !root->left && !root->right;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root == NULL) return root;

        root->left = removeLeafNodes(root->left, target);   // traverse left
        root->right = removeLeafNodes(root->right, target); // traverse right

        if(root->val == target && isLeafNode(root)) { // remove this node if leaf only
            
            if(root->left == NULL) {
                return root->right;
            }
            else if(root->right == NULL) {
                return root->left;
            }

            TreeNode *temp = minValueNode(root->right);
            root->val = temp->val;

            root->right = removeLeafNodes(root->right, temp->val);
        }
        return root;
    }
};