// https://leetcode.com/problems/print-binary-tree/

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
    
    int traverse(TreeNode *head, int height)
    {
        if(head == NULL) return height;
        
        int lHeight = traverse(head->left, height+1);
        int rHeight = traverse(head->right,height+1);
        
        return max(lHeight, rHeight);
    }
    
    /**
     * SIMILAR TO BINARY SEARCH but on the totalNodes of the tree
     * */
    void fillTree(TreeNode *head, int start, int end, int maxHeight, int height, vector<vector<string>>& result)
    {
        if(head == NULL) return;
        
        if(end == start) {
            result[height][start] = to_string(head->val);
            return;
        }
        
        // find the middle element of the maxLevel to insert the current head in that range mid
        int mid = (end+start)/2;
        
        // insert head->val in the resultant
        result[height][mid] = to_string(head->val);
        
        fillTree(head->left, start, mid-1, maxHeight, height+1, result);
        fillTree(head->right, mid+1, end, maxHeight, height+1, result);
        
        return;
    }
        
    vector<vector<string>> printTree(TreeNode* root) {
        
        vector<vector<string>>result;
        
        if(root == NULL) return result;
        
        // maximum height of the tree
        int height = traverse(root, 0);
        cout << height << endl;
        
        // Number of nodes in the tree with height 'h'
        int totalNodes = static_cast<int>(pow(2,height))-1;
        cout << totalNodes << endl;
        
        for(int i = 0; i != height; i++) {
            vector<string>level(totalNodes, "");
            result.push_back(level);
        }
        
        fillTree(root, 0, totalNodes-1, height, 0, result);
        
        return result;
    }
};