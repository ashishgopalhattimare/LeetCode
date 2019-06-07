// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    
    void preorder(TreeNode *head, map<int, vector<int>>& hashmap, int height) {
        if(head == NULL) return;
        
        hashmap[height] .push_back(head->val);
        
        preorder(head->left, hashmap, height+1);
        preorder(head->right, hashmap, height+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, vector<int>>hashmap;
        
        int height = 1;
        
        preorder(root, hashmap, height);
        
        vector<double>result;
        long long int sum;
        for(auto itr = hashmap.begin(); itr != hashmap.end(); itr++) {
            
            sum = 0;
            for(int x : itr->second) {
                sum += x;
            }
            result.push_back(sum / (1.0 * itr->second.size()));
        }
        return result;
    }
};
