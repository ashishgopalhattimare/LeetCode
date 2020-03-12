// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    long long int result = 0, total = 0;
    
public:
    
    void traversal(TreeNode *root) {
        if(root == NULL) return;
        
        traversal(root->right); traversal(root->left);
        total += root->val;
    }
    
    long long int inorder(TreeNode *root) {
        
        if(root == NULL) return 0;
        
        long long int subSum = root->val + inorder(root->left) + inorder(root->right);
        
        result = max(result, subSum * (total-subSum));
        
        return subSum;
    }
    
    int maxProduct(TreeNode* root) {
        
        traversal(root); inorder(root);
        
        return result % (int)(1e9+7);
    }
};