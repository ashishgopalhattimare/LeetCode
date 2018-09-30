// https://leetcode.com/problems/path-sum-ii/

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
    
    void traverse(TreeNode *head, vector<vector<int>>& result, vector<int>& path, int csum, int sum)
    {
        if(head == NULL) {
            return;
        }
        
        if(head->left == NULL && head->right == NULL) {
            path.push_back(head->val);
            if(sum == csum + head->val) {
                result.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        path.push_back(head->val);
        traverse(head->left, result, path, csum + head->val, sum);
        traverse(head->right, result, path, csum + head->val, sum);
        path.pop_back();
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>>result;
        vector<int>path;
        
        traverse(root, result, path, 0, sum);
        
        return result;
    }
};