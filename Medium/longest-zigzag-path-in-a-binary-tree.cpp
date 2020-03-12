// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
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
    int result = 0;
    
    void traversal (TreeNode* root, int height, char dir) {
        
        result = max(result, height-1);
        if(root == NULL) return;
        
        // printf("%d - %d\n", root->val, height);
        
        if(dir == 'r') traversal(root->right, 1, 'r');
        else traversal(root->right, height+1, 'r');
        
        if(dir == 'l') traversal(root->left, 1, 'l');
        else traversal(root->left, height+1, 'l');
        
    }
        
    int longestZigZag(TreeNode* root) {
        
        traversal(root, 0, 'x');
        return result;
    }
};