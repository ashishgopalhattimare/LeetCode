// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/

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
    
    void traverse(TreeNode *root, vector<int>& nums, long long int &result) {
        if(root == NULL) return;
        
        nums.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) { // leaf node
            
            int k = 0, val = 0;
            for(int i = nums.size()-1; i >= 0; i--) {
                if(nums[i]) {
                    val = val + static_cast<int>(pow(2, k));
                }
                k++;
            }
            result += val;
        }
        
        traverse(root->right, nums, result);
        traverse(root->left, nums, result);
        
        nums.pop_back();
        
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        long long int result = 0;
        
        vector<int>nums;
        traverse(root, nums, result);
        
        return result;
    }
};
