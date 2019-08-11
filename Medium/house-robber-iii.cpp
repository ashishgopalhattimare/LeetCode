// https://leetcode.com/problems/house-robber-iii/
// Memoization over subproblems in the subtree

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
    
    unordered_map<TreeNode*, int>map;
    
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        // Ignore repeated subproblem in the subtree
        if(map.find(root) != map.end()) {
            return map[root];
        }
        
        int value = 0;
        if(root->left) {
            value += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right) {
            value += rob(root->right->left) + rob(root->right->right);
        }
        
        map[root] = max(root->val + value, rob(root->left) + rob(root->right));
        
        return map[root];
    }
};
