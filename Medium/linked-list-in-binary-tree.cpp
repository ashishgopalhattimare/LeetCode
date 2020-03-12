// https://leetcode.com/problems/linked-list-in-binary-tree/
// Medium

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    bool exists(TreeNode *root, ListNode *head) {
        
        if((!root && !head) || !head) return true;
        if(root == NULL) return false;
        
        if(root->val == head->val) {
            return exists(root->left, head->next) || exists(root->right, head->next);
        }
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(root) {
            if(head->val == root->val && exists(root, head)) {
                return true;
            }
            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
        return false;
    }
};