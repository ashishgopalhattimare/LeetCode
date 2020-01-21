// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Medium

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
    
    void operation(stack<TreeNode*>& st, TreeNode *ptr) {
        while(ptr) {
            st.push(ptr);
            ptr = ptr->left;
        }
    }
    
    void emptyStack(stack<TreeNode*>& st, vector<int>& result) {
        TreeNode *ptr;
        while(!st.empty()) {
            ptr = st.top();
            
            result.push_back(ptr->val);
            st.pop();
                
            if(ptr->right) operation(st, ptr->right);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        stack<TreeNode*> st1, st2;
        TreeNode *ptr1 = root1, *ptr2 = root2;
        
        vector<int>result;
        
        operation(st1, ptr1);
        operation(st2, ptr2);
        
        while(!st1.empty() && !st2.empty()) {
            
            ptr1 = st1.top(); // top of stack 1
            ptr2 = st2.top(); // top of stack 2
            
            if(ptr1->val <= ptr2->val)
            {
                result.push_back(ptr1->val);
                st1.pop();
                
                if(ptr1->right) operation(st1, ptr1->right);
            }
            else
            {
                result.push_back(ptr2->val);
                st2.pop();
                
                if(ptr2->right) operation(st2, ptr2->right);
            }
        }
        
        if(!st1.empty()) emptyStack(st1, result);
        if(!st2.empty()) emptyStack(st2, result);
        
        return result;
    }
};