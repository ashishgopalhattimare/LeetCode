// https://leetcode.com/problems/maximum-binary-tree-ii/description/

// This is not done but the output is following the maximum binary tree property

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Alternate Solution, why does it work though

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == NULL) { 
            return new TreeNode(val);
        }
        
        if (root->val < val) {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp; 
        }
        else {
            root->right = insertIntoMaxTree(root->right, val);
            return root; 
        }
    }
};

**/

class Solution {
public:
    bool iterate(TreeNode *head, int val, unordered_map<TreeNode*, pair<int, int> >& hash)
    {
        if(head == NULL || head->val < val) return false;
        
        bool l = iterate(head->left, val, hash);
        bool r = iterate(head->right,val, hash);
        
        if(l == false && r == false) {
            
            int lval = hash[head].first;
            int rval = hash[head].second;
            
            TreeNode *temp = new TreeNode(val);
            if(lval < rval) {
                temp->left = head->left;
                head->left = temp;
            }
            else {
                temp->left = head->right;
                head->right = temp;
            }
            
            return true;
        }
        return l || r;
    }
    
    int height(TreeNode *root, unordered_map<TreeNode*, pair<int, int> >& hash)
    {
        if(root == NULL || root->val == 0) return 0;
        
        int l = height(root->left, hash);
        int r = height(root->right, hash);
        
        hash[root] = make_pair(l, r);
        
        return max(l, r) + 1;
    }
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        
        if(root == NULL) return new TreeNode(val);
        
        if(root->val < val) {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            
            return temp;
        }
        
        unordered_map<TreeNode*, pair<int, int> > hash;
        
        int h = height(root, hash);
        
        bool i = iterate(root, val, hash);
        
        return root;
    }
};
