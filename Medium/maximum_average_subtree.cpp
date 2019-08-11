// https://leetcode.com/contest/biweekly-contest-4/problems/maximum-average-subtree/
// Bi-Weekly Contest
// Medium-Easy

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
    
    double maximumAverage = -1;
    
    pair<long long,int> traversal(TreeNode *head) { // <int,int> : <totalsum, no.of nodes>
        if(head == NULL) return {0, 0};
        
        pair<long long,int> left = traversal(head->left);
        pair<long long,int> right = traversal(head->right);
        
        long long totalSum = head->val + (left.first + right.first);
        int nodes = (left.second + right.second) + 1;
        
        maximumAverage = max(maximumAverage, totalSum / (nodes*1.0));
        
        return {totalSum, nodes};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        
        traversal(root);
        
        return maximumAverage;
    }
};
