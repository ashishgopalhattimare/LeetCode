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
    
    int dfs(TreeNode *head, unordered_map<TreeNode *, int>& hash)
    {
        // if the root is null, return --> height is 0 to its parent node left/right
        if(head == NULL) return 0;
        
        // compute left height and right height
        int left = dfs(head->left, hash);
        int right = dfs(head->right, hash);
        
        // store the maximum height of the left and right subtree and make it the maximum diameter from this node
        hash[head] = left + right;
        
        // return the maximum height of the left or right subtree
        // 1 + because it is return to its parent as one edge is used
        return 1 + max(left, right);
    }
        
    int diameterOfBinaryTree(TreeNode* root) {
        
        unordered_map<TreeNode*, int> hash;
        
        if(root == NULL) return 0;
        
        int diameter = dfs(root, hash);
        
        diameter = INT_MIN;
        for(auto itr = hash.begin(); itr != hash.end(); itr++) {
            diameter = max(diameter, itr->second);
        }
        
        return diameter;
    }
};