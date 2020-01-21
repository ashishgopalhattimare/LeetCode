// https://leetcode.com/problems/deepest-leaves-sum/
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
    int deepestLeavesSum(TreeNode* root) {
        
        int resultSum = 0, temp, size;
        
        list<TreeNode*>ll = {root};
        TreeNode *ptr;
        
        while(!ll.empty()) {
            
            size = ll.size();
            temp = 0;
            while(size--) {
                ptr = ll.front();
                
                temp += ptr->val;
                ll.pop_front();
                
                if(ptr->right) ll.push_back(ptr->right);
                if(ptr->left) ll.push_back(ptr->left);
            }
            resultSum = temp;
        }
        
        return resultSum;
    }
};