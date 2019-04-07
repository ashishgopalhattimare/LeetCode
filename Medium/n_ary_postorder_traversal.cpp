// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// 0.5 min

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
    void preorder(Node *root, vector<int>& result) {
        if(root == NULL) return;
        
        for(Node * x : root->children) {
            preorder(x, result);
        }
        result.push_back(root->val);
        
        return;
    }
    
    vector<int> postorder(Node* root) {
        
        vector<int>result;
        
        preorder(root, result);
        
        return result;
    }
};
