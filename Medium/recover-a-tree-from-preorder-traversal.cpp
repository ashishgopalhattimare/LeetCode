// https://leetcode.com/contest/weekly-contest-132/problems/recover-a-tree-from-preorder-traversal/

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
    
    TreeNode *traversal(TreeNode *head, int curr, int depth, int value, bool *located)
    {
        // if the leaf is reached
        if(head == NULL) {
            // if this the required depth of the value
            if(curr == depth) {
                *located = true; // value positioned
                return new TreeNode(value); // new subtree
            }
            
            // not this depth
            return NULL;
        }
        
        // if the right subtree exists, move there
        if(head->right) {
            head->right = traversal(head->right, curr+1, depth, value, located);
        }
        else {
            // try to position this value in the left subtree
            if(*located == false) {
                head->left = traversal(head->left, curr+1, depth, value, located);
            }
            // if the value cannot be positioned in the left subtree, go to right subtree
            if(*located == false) {
                head->right = traversal(head->right, curr+1, depth, value, located);
            }
        }
        
        return head;
    }
    
    TreeNode* recoverFromPreorder(string S) {
        
        int k = 0, dept, value;
        
        // construct the value with its depth
        dept = 0;
        
        bool located; // if the value is located in the tree or not
        TreeNode *root = NULL;
        for( ; k < S.length(); k++) {
            
            value = 0;
            while(k < S.length() && S[k] == '-') {
                dept++; k++;
            }
            while(k < S.length() && S[k] != '-' ) {
                value = value*10 + (S[k]-'0');
                k++;
            }
            
            located = false; // not currently located
            root = traversal(root, 0, dept, value, &located);
            
            dept = 1;
        }
        
        return root;
    }
};
