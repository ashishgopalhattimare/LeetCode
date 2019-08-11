// https://leetcode.com/problems/increasing-order-search-tree/
// Easy-Medium

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
    TreeNode* increasingBST(TreeNode* head) {
        
        TreeNode *curr = head;
        TreeNode *left, *right;
        
        TreeNode *prev = NULL, *leftPrev;
        
        while(curr) {
            
            // Check if the left of root is there
            left = curr->left;
            if(left == NULL) { // if not
                prev = curr;
                curr = curr->right;
            }
            else { // if yes
                leftPrev = curr;
                while(left->left) { // get the left most node of the left subtree
                    leftPrev = left;
                    left = left->left;
                }
                
                right = left; // get the rightmost node of the right subtree of the left
                while(right->right) {
                    right = right->right;
                }
                
                leftPrev->left = NULL;
                right->right = curr;
                
                if(prev == NULL) { // still need to decide the root node
                    head = (curr = left);
                }
                else {
                    prev->right = left;
                    curr = left;
                }
            }
            
        }
        
        return head;
    }
};
