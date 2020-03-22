// https://leetcode.com/problems/balance-a-binary-search-tree/
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
    
    void traversal(TreeNode *root, list<int>& ll) {
        
        if(root == NULL) return;
        
        traversal(root->left, ll);
        ll.push_back(root->val);
        traversal(root->right,ll);
    }
    
    TreeNode *buildBST(vector<int>& arr, int start, int end)
    {
        if(start > end) return NULL;
        
        int mid = start + (end-start)/2;
        
        TreeNode *temp = new TreeNode(arr[mid]);
        
        temp->left = buildBST(arr, start, mid-1);
        temp->right = buildBST(arr, mid+1, end);
        
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        list<int>ll;
        traversal(root, ll);
        
        vector<int>arr(ll.size());
        for(int i = 0; !ll.empty(); i++) {
            arr[i] = ll.front();
            ll.pop_front();
        }
        
        return buildBST(arr, 0, arr.size()-1);
    }
    
};