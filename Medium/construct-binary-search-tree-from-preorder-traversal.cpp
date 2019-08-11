// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    
    int index;
    TreeNode* constructTree(TreeNode *head, vector<int>& preorder, int low, int high)
    {
        if(index >= preorder.size()) return head;
        
        if(low <= preorder[index] && preorder[index] <= high) {
            head = new TreeNode(preorder[index++]);
        }
        else return head;
        
        head->left = constructTree(head->left, preorder, low, preorder[index-1]-1);
        head->right = constructTree(head->right,preorder, preorder[index-1]+1, high);
        
        return head;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode *head = NULL;
        index = 0;
        
        int maxim = INT_MIN, minim = INT_MAX;
        for(int i = 0; i < preorder.size(); i++){
            minim = min(minim, preorder[i]);
            maxim = max(maxim, preorder[i]);
        }        
        head = constructTree(head, preorder, minim, maxim);
        
        return head;
    }
};
