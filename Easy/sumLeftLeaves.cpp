/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://leetcode.com/problems/sum-of-left-leaves/description/


class Solution {
public:
    
    int sum;
    
    void inorder(TreeNode *head, char position)
    {
        if(head == NULL) return;
        
        if(head->left == NULL && head->right == NULL) {
            if(position == 'L') {
                sum += head->val;
            }
        }
        
        inorder(head->left, 'L');
        inorder(head->right,'R');
        
        return;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        sum = 0;
        
        inorder(root,'H');
        
        return sum;
    }
};