// https://leetcode.com/problems/delete-nodes-and-return-forest/
// Weekly-Contest
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

	bool deleted(TreeNode *prev, TreeNode *head, int target, vector<TreeNode*>& result, int source) 
	{
        if(head == NULL) return false;
        if(head->val == target) {
            if(head->right) result.push_back(head->right);
            if(head->left) result.push_back(head->left);
            
            if(prev) {
                if(prev->right == head) prev->right = NULL;
                else prev->left = NULL;
            }
            else {
                result.erase(result.begin()+source);
            }
            return true;
        }
        
        return deleted(head, head->left, target, result, source) || 
            deleted(head, head->right, target, result, source);
	}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*>result = {root};
        for(int x : to_delete) {
            for(int i = 0; i < result.size(); i++) {
                if(deleted(NULL, result[i], x, result, i)) {
                    break;
                }
            }
        }
        
        return result;
    }
};
