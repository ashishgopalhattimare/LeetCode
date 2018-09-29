// https://leetcode.com/problems/binary-tree-paths/description/

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
    
    void inorder(TreeNode *root, vector<int>& path, vector<string>& result)
    {
        if(root == NULL) return;
        
        if(!(root->left) && !(root->right)) {
            path.push_back(root->val);
            
            if(path.size() >= 2) {
                string str = "";
                str.append(to_string(path[0]));
                
                for(int i = 1; i < path.size(); i++) {
                    str.append("->");
                    str.append(to_string(path[i]));
                }
                
                result.push_back(str);
            }
            
            path.pop_back();
            return;
        }
        
        path.push_back(root->val);
        
        inorder(root->left, path, result);
        inorder(root->right, path, result);
        
        path.pop_back();
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<int>path;
        vector<string>result;
        
        if(root == NULL) return result;
        
        if(!(root->left) && !(root->right)) {
            string str = "";
            str.append(to_string(root->val));
            
            result.push_back(str);
            return result;
        }
        
        inorder(root, path, result);
        
        return result;
    }
};
