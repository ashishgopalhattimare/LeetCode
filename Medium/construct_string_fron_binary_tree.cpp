// https://leetcode.com/problems/construct-string-from-binary-tree/description/

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
    string result;

    void preorder(TreeNode *head) {
        
        if(head == NULL) return;
        
        result.append(to_string(head->val));
        
        // If the root has left or child subtree
        if(head->left || head->right) {
            // if the left exist
            if(head->left) {
                result.push_back('(');
                preorder(head->left);
                result.push_back(')');
            }
            // if the left is not there, but right exist
            else if(head->right) {
                result.push_back('(');
                result.push_back(')');
            }

            // if the right exist
            if(head->right) {
                result.push_back('(');
                preorder(head->right);
                result.push_back(')');
            }
        }
    }
    string tree2str(TreeNode* root) {
        
        result = "";
        preorder(root);
        
        return result;
    }
};
