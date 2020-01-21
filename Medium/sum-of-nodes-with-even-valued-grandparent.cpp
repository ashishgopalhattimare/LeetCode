// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
private:
    int totalSum = 0;
    void traversal(TreeNode *root) {
        
        if(!root) return;
        
        if(root->val % 2 == 0) {
            if(root->left) {
                if(root->left->left) totalSum += root->left->left->val;
                if(root->left->right) totalSum += root->left->right->val;
            }
            if(root->right) {
                if(root->right->left) totalSum += root->right->left->val;
                if(root->right->right) totalSum += root->right->right->val;
            }
        }
        
        traversal(root->right);
        traversal(root->left);
    }
public:
    
    int sumEvenGrandparent(TreeNode* root) {
        
        totalSum = 0; traversal(root);
        return totalSum;
    }
};