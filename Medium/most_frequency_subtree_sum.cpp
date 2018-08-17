// https://leetcode.com/problems/most-frequent-subtree-sum/description/

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
    
    int frequencyTree(TreeNode *head, unordered_map<int,int>& hash)
    {
        if(head == NULL) return 0;
        
        int left = frequencyTree(head->left, hash);
        int right = frequencyTree(head->right, hash);
        
        int rootSum = left + right + head->val;
        
        if(hash.find(rootSum) == hash.end()) {
            hash[rootSum] = 1;
        }
        else {
            hash[rootSum]++;
        }
        
        return rootSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int, int>hash;
        
        int f = frequencyTree(root, hash);
        
        int maxFrequency = INT_MIN, count = 0;
        
        for(auto itr = hash.begin(); itr != hash.end(); itr++) {
            if(maxFrequency < itr->second) {
                maxFrequency = itr->second;
            }
        }
        
        vector<int> result;
        for(auto itr = hash.begin(); itr != hash.end(); itr++) {
            if(itr->second == maxFrequency) {
                result.push_back(itr->first);
            }
        }
        
        return result;
    }
};