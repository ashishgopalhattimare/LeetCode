// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool compare(pair<int,int>& a, pair<int,int>& b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return (a.second < b.second);
}

class Solution {
    
public:
    
    void traverse(TreeNode *root, map<int, vector< pair<int,int> >>& hash, int level, int height)
    {
        if(root == NULL) return;
        hash[level].push_back(make_pair(root->val, height));
            
        traverse(root->left, hash, level-1, height+1);
        traverse(root->right, hash, level+1,height+1);
        
        return;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector< pair<int,int> > > hashmap;
        
        vector<vector<int>> result;
        
        traverse(root, hashmap, 0, 0);
        
        for(auto itr = hashmap.begin(); itr != hashmap.end(); itr++) {
        	
			vector< pair<int,int> > arr = itr->second;
            
            sort(arr.begin(), arr.end(), compare);
            
            vector<int> temp;
            for(int i = 0; i < arr.size(); i++) {
                temp.push_back(arr[i].first);
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
