// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// store path approach

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
    
    bool pathFound;
    
    void path_to_node(TreeNode *root, TreeNode *p, int level, stack<pair<TreeNode *, int> >& path)
    {
        if(root == NULL) return;
        
        path.push(make_pair(root, level));
        
        if(root->val == p->val) {
            pathFound = true;
            return;
        }
        
        if(!pathFound) path_to_node(root->left, p, level+1, path);
        if(!pathFound) path_to_node(root->right,p, level+1, path);
        
        if(!pathFound) path.pop();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        
        stack<pair<TreeNode *, int> > pathP;
        stack<pair<TreeNode *, int> > pathQ;
        
        pathFound = false;
        // store the path to the p node along with the level
        path_to_node(root, p, 0, pathP);
        
        pathFound = false;
        // store the path to the q node along with the level
        path_to_node(root, q, 0, pathQ);
        
        pair<TreeNode *, int> pp, qq;
        
        TreeNode *lca = root;
        while(!pathP.empty() && !pathQ.empty()) {
            
            pp = pathP.top(); qq = pathQ.top();

            // if the top of the both the stack point to the same node value as all
            // node are distinct
            if((pp.first)->val == (qq.first)->val) {
                lca = (pp.first);
                break;
            }

            // if the level of the p node is deeper than the q node
            // move p node to one level up
            else if(pp.second > qq.second) {
                pathP.pop();
            }
            // if the level of the q node is deeper than the q node
            // move q node to one level up
            else {
                pathQ.pop();
            }
        }
        
        return lca;
    }
};