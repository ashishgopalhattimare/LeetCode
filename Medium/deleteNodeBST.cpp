// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

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
    
    TreeNode *successor(TreeNode *head)
    {
        TreeNode *curr = head;
        while(curr->left) {
            curr = curr->left;
        }
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL) return NULL;
        
        if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        
        else {
            if(root->left == NULL && root->right == NULL) { // leaf node
                return NULL;
            }
            else {
                if(root->left == NULL) {
                    return root->right;
                }
                else if(root->right == NULL) {
                    return root->left;
                }
                else {
                    TreeNode *temp = successor(root->right);
                    root->val = temp->val;
                    
                    // recussive remove the key node until it is leaf or one side is null
                    root->right = deleteNode(root->right, temp->val);
                }
            }
        }
        
        return root;
    }
};