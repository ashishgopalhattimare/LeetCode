// https://leetcode.com/problems/binary-tree-pruning/description/

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
    
    bool inorder1(TreeNode *root) {
        if(root == NULL) return false;
        
        bool left = inorder1(root->left); // left subtree check
        bool right = inorder1(root->right); //  right subtree check
        
        // left check
        if(left == false) root->left = NULL; // if the left has no 1 -> false left subtree -> make the left subtree NULL
        if(right == false) root->right = NULL; // if the left has no 1 -> false right subtree -> make the right subtree NULL
        
        if(root->val == 1) return true; // if the root value is 1 -> keep the root and its bottom tree
        if(left || right) return true; // if the root is not 1 but left || right has 1 in its subtree -> keep the bottom tree
        
        return false; // if the child subtree are 0 and the root is 0, NULL the entire tree
    }
    
    void inorder(TreeNode *head)
    {
        if(head == NULL) return;
        
        printf("%d ", head->val);
        inorder(head->left);
        inorder(head->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        bool head = inorder1(root);
        
        return root;
    }
};