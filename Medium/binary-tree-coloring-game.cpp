// https://leetcode.com/problems/binary-tree-coloring-game/submissions/
// Medium
// Time Complexity : O(n)
// Space : O(height)

// Little Tricky

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
    
    int leftSubtree = 0, rightSubtree = 0;
    
    int countNodes(TreeNode *root, int x) {
        if (root == NULL) return 0;
        
        int l = countNodes(root->left, x);
        int r = countNodes(root->right,x);
        
        if(x == root->val) {
            rightSubtree = r;
            leftSubtree = l;
        }
        
        return l + r + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        countNodes(root, x);
        
        // Check if the leftSubtree or rightSubtree or the leftOver node count
        // is greater than half of the whole tree count
        return max(max(leftSubtree, rightSubtree), n - (leftSubtree + rightSubtree+1)) > n/2;
    }
};
