// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if(!root) return;
        
        stack<TreeLinkNode*>st;
        vector<TreeLinkNode*>V;
        
        TreeLinkNode *node;
        
        st.push(root);
        root->next = NULL;
        
        while(!st.empty())
        {
            while(!st.empty()) {
                node = st.top();
                if(node->left) V.push_back(node->left);
                if(node->right) V.push_back(node->right);
                
                st.pop();
            }
            
            if(V.size()) {
                for(int i = 0; i < V.size()-1; i++) {
                    V[i]->next = V[i+1];
                }
                if(V.size() > 0)
                V[V.size()-1]->next = NULL;
                
                while(V.size()) {
                    st.push(V[V.size()-1]);
                    V.pop_back();
                }
            }
        }
    }
};