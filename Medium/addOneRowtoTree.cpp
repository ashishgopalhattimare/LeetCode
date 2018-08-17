// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        
        if(d == 1) {
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            
            return newNode;
        }
        TreeNode *ptr;
        stack<TreeNode*>st, temp;
        
        int height = 1;
        
        st.push(root);
        while(!st.empty()) {
            if(d == height + 1) {
                
                while(!st.empty()) {
                    ptr = st.top();
                    
                    TreeNode *lChild = new TreeNode(v);
                    TreeNode *rChild = new TreeNode(v);
                    
                    rChild->right = ptr->right;
                    lChild->left = ptr->left;
                    
                    ptr->right = rChild;
                    ptr->left = lChild;
                    
                    st.pop();
                }
                
                break;
            }
            while(!st.empty()) {
                ptr = st.top();
                
                if(ptr->right) temp.push(ptr->right);
                if(ptr->left) temp.push(ptr->left);
                st.pop();
            }
            while(!temp.empty()) {
                st.push(temp.top());
                temp.pop();
            }
            height++;
        }
        
        return root;
    }
};