// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

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
    bool nodeFound;
    
    vector<int> result;
    
    void subTree(TreeNode *root, int k)
    {
        if(root == NULL) return;
        
        if(k == 0) result.push_back(root->val);
        
        subTree(root->left, k - 1);
        subTree(root->right,k - 1);
    }
    TreeNode *prev = NULL;
    void inorder(TreeNode *root, TreeNode *target, int *K)
    {
        if(root == NULL) return;
        
        if(!nodeFound) {
            if(target == root) {
                nodeFound = true;
                
                subTree(root, *K);
                prev = root;
                return;
            }
            
            if(!nodeFound) inorder(root->left, target, K);
            if(!nodeFound) inorder(root->right,target, K);
        }
        
        if(nodeFound) {
            *K = *K - 1; // deduce distance as we recursive go back to the root
            // if the center is found
            
            if(*K == 0) { // if the node is among the answer
                result.push_back(root->val);
                return;
            }
            
            // if the left subtree is not visited yet
            if(prev != NULL && root->left && root->left != prev) {
                subTree(root->left, *K - 1); // cosider it as root node
            }

            // if the right subtree is not visited yet
            if(prev != NULL && root->right && root->right != prev) {
                subTree(root->right, *K - 1); // consider it as root node
            }
        }
        
        prev = root;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        nodeFound = false;
        inorder(root, target, &K);
        
        return result;
    }
};