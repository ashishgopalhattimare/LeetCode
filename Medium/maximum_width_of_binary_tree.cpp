// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        TreeNode *ptr;
        queue<TreeNode*>q1, temp1;
        queue<int>q2, temp2;
        
        int maxWidth = INT_MIN;
        
        q1.push(root); q2.push(1);
        while(!q1.empty()) {
            
            // get the width of the current level in the queue
            maxWidth = max(maxWidth, q2.back() - q2.front() + 1);
            while(!q1.empty()) {
                ptr = q1.front();
                
                // if the left node is present
                if(ptr->left) {
                    temp1.push(ptr->left);
                    temp2.push(2*q2.front()-1);
                    
                }

                // if the right node is present
                if(ptr->right){
                    temp1.push(ptr->right);
                    temp2.push(2 * q2.front());
                }
                
                q2.pop();
                q1.pop();
            }
            
            while(!temp1.empty()) {
                
                q1.push(temp1.front());
                q2.push(temp2.front());
                
                temp1.pop();
                temp2.pop();
            }
        }
        
        return maxWidth;
    }
};