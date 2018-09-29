// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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
    
    void inorderF(TreeNode *root, int *minim)
    {
        if(root == NULL) return;
        
        inorderF(root->left, minim);
        *minim = min(*minim, root->val);
        inorderF(root->right, minim);
    }
    
    void inorderFS(TreeNode *root, int minF, int *minS)
    {
        if(root == NULL) return;
        
        inorderFS(root->left, minF, minS);
        
        if(minF < root->val && root->val < *minS) {
            *minS = root->val;
        }
        
        inorderFS(root->right, minF, minS);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int minF = INT_MAX;
        int minS = INT_MAX;
        
        inorderF(root, &minF);
        inorderFS(root, minF, &minS);
        
        if(minF == INT_MAX || minS == INT_MAX) return -1;
        
        return minS;
    }
};
