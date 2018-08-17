// http://qa.geeksforgeeks.org/3976/qa.geeksforgeeks.org/3976/flattening-a-binary-tree.html

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
    void flatten(TreeNode* root) {
        
        
        TreeNode *ptr = root;
        TreeNode *l, *r;
        
        while(ptr) {
            if(ptr->left) {
                l = ptr->left;
                while(l->right) {
                    l = l->right;
                }
                l->right = ptr->right;
                
                ptr->right = ptr->left;
                ptr->left = NULL;
            }
            
            ptr = ptr->right;
        }
    }
};