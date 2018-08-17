// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if(root == NULL) return result;
        
        TreeNode *ptr;
        stack<TreeNode*>st, temp;
        
        st.push(root);
        
        while(!st.empty()) {
            
            while(!st.empty()) {
                ptr = st.top();
                if(ptr->left) temp.push(ptr->left);
                if(ptr->right) temp.push(ptr->right);
                
                st.pop();
            }

            // FLICK -> directly push the last Node incountered in the st
            //          stack while iterating levels
            result.push_back(ptr->val);
            
            while(!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
        }
        
        return result;
    }
};