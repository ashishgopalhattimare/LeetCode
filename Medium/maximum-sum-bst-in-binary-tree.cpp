// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// Hard

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Data {
    int min, max, total;
    bool bst;
};

class Solution {
public:
    
    int result = 0;
    
    Data traversal(TreeNode* root) {
        
        int val = root->val;
        
        if(root->left == NULL && root->right == NULL) {
            result = max(result, val);
            return {val, val, val, true};
        }
        
        Data left, right;
        
        if(root->right) right = traversal(root->right);
        if(root->left) left = traversal(root->left);
        
        int treeSum;
        if(root->right && root->left) { // Both subtree exists
            
            if(left.max < val && val < right.min && left.bst && right.bst) {
                treeSum = left.total+val+right.total;
                result = max(result, treeSum);
                
                return {min(left.min, val), max(right.max, val), treeSum, true};
            }
            goto END;
        }
        
        else if(root->right) { // only right exist
            
            if(val < right.min && right.bst) {
                treeSum = val+right.total;
                result = max(result, treeSum);
                
                return {val, right.max, treeSum, true};
            }
            goto END;
        }
        
        // Only left subtree exist
        if(left.max < val && left.bst) {
            treeSum = val+left.total;
            result = max(result, treeSum);
                
            return {left.min, val, treeSum, true};
        }
        
        END:
        return {INT_MAX, INT_MIN, 0, false};
    }
    int maxSumBST(TreeNode* root) {
        
        traversal(root);
        
        return result;
    }
};