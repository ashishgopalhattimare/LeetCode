// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    
    long long int sumTotal = 0;
    
    void inorder(TreeNode *head, int sum)
    {
        if(head == NULL) return;
        
        if(head->left == NULL && head->right == NULL) {
            sumTotal += (sum * 10 + head->val);
            return;
        }
        
        inorder(head->left, sum * 10 + head->val);
        inorder(head->right,sum * 10 + head->val);
    }
    
    int sumNumbers(TreeNode* root) {
        
        sumTotal = 0;
        inorder(root, 0);
        
        return sumTotal;
    }
};