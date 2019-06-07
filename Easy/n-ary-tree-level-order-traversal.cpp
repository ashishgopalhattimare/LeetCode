// https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Easy

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    void inorder(Node *root, map<int,vector<int>>& mp, int height) {
        if(root == NULL) return;
        
        mp[height].push_back(root->val);
        for(int i = 0; i < root->children.size(); i++) {
            inorder(root->children[i], mp, height+1);
        }
        return;
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        map<int,vector<int>>mp;
        inorder(root, mp, 1);
        
        
        vector<vector<int>>result;
        for(auto itr = mp.begin(); itr != mp.end(); itr++) {
            result.push_back(itr->second);
        }
        return result;
    }
};
