// https://leetcode.com/problems/cousins-in-binary-tree/
// Easy

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
    
    void traverse(TreeNode *root, TreeNode *parent, int x, int y, vector<pair<TreeNode*,int>>& info, int level) {
        if(root == NULL) return;
        
        if(root->val == x || root->val == y) {
            info.push_back(make_pair(parent, level));
            return;
        }
        
        traverse(root->right, root, x, y, info, level+1);
        traverse(root->left, root, x, y, info, level+1);
    } 
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        vector<pair<TreeNode*,int>>info; // store their parent and level
        
        traverse(root, NULL, x, y, info, 1); // traverse the tree
        
        if(info.size() != 2) return false; // if one is the child of other return false;
        
        if(info[0].second != info[1].second) return false; // if they are not the same level
        return info[0].first != info[1].first; // same level but not same parent, return true
    }
};
