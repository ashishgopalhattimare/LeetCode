// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    
    void preorder(TreeNode *head, map<int, vector<int>>& hashmap, int height) {
        if(head == NULL) return;
        
        hashmap[height] .push_back(head->val);
        
        preorder(head->left, hashmap, height-1);
        preorder(head->right, hashmap, height-1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int, vector<int>>hashmap;
        
        int height = INT_MAX-2;
        
        preorder(root, hashmap, height);
        
        vector<vector<int>>result;
        for(auto itr = hashmap.begin(); itr != hashmap.end(); itr++) {
            result.push_back(itr->second);
        }
        return result;
    }
};
