// https://leetcode.com/problems/flip-equivalent-binary-trees/description/

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
    
    void modifyTree(TreeNode *head)
    {
        // if the head is NULL
        if(head == NULL) return;
        
        // if both the left and right node are NULL
        if(head->left == NULL && head->right == NULL) return;
        
        // if the left node is present && right node is absent or left is smaller than right node, swap
        else if(head->left && (head->right == NULL || (head->left->val < head->right->val))) {
            TreeNode *temp = head->left;
            head->left = head->right;
            head->right = temp;
        }
        
        // traverse both direction
        modifyTree(head->left);
        modifyTree(head->right);
        
        return;
    }
    
    bool equivalentTree(TreeNode *root1, TreeNode *root2)
    {
        if(!root1 && !root2) return true;
        if(root1 && root2) {
            if(root1->val != root2->val) return false;
            
            if(!equivalentTree(root1->left, root2->left) || !equivalentTree(root1->right, root2->right)) return false;
        }
        else {
            return false;
        }
        return true;
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        modifyTree(root1);
        modifyTree(root2);
    
        return equivalentTree(root1, root2);
    }
};
