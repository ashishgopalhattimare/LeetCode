// https://leetcode.com/contest/weekly-contest-132/problems/maximum-difference-between-node-and-ancestor/

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
    
    pair<int,int> traversal(TreeNode *head, int &result)
    {
        if(head->left == NULL && head->right == NULL) return make_pair(head->val, head->val);
        
        int lvalue = head->val, rvalue = head->val;
        if(head->left) {
            pair<int,int> temp = traversal(head->left, result);
            
            lvalue = min(min(lvalue, temp.first), temp.second);
            rvalue = max(max(rvalue, temp.first), temp.second);
        }
        if(head->right) {
            pair<int,int> temp = traversal(head->right, result);
            
            lvalue = min(min(lvalue, temp.first), temp.second);
            rvalue = max(max(rvalue, temp.first), temp.second);
        }
        
        result = max(max(result, abs(head->val-lvalue)), abs(head->val-rvalue));
        
        return make_pair(lvalue,rvalue);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        
        pair<int,int> temp = traversal(root, result);
        
        return result;
    }
};
       // [8,null,1,5,6,2,4,0,null,7,3]
       //
       //     8
       //    / \
       //   3   10
       //  /\    \
       // 1  6    14
       //   / \   /
       //   4 7  13
