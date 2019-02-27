// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

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
    bool isCompleteTree(TreeNode* root) {
        
        if(root == NULL) return true;
        
        bool complete = true;
        bool zeroFound = false;
        
        deque<TreeNode*>dq;
        
        dq.push_back(root);
        TreeNode *curr;
        
        while(!dq.empty())
        {
            curr = dq.front();
            
            if(curr && zeroFound) {
                complete = false;
                break;
            }
            else if(!curr) {
                zeroFound = true;
                
                dq.pop_front();
                continue;
            }
            
            dq.push_back(curr->left);
            dq.push_back(curr->right);
            
            dq.pop_front();
        }
        
        while(!dq.empty()) dq.pop_front();
        
        return complete;
    }
};
