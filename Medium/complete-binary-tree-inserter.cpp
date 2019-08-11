// https://leetcode.com/problems/complete-binary-tree-inserter/
// Medium
// Design Implement
// Deque + Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    
    TreeNode *head;
    list<TreeNode*>ll;
    
    CBTInserter(TreeNode* root) {
        head = root;
        
        ll.push_back(root);
        while(true) {
            TreeNode *curr = ll.front();
            if(curr->right) {
                
                ll.pop_front();
                ll.push_back(curr->left);
                ll.push_back(curr->right);
            }
            else break;
        }
    }
    
    int insert(int val) {
        if(head == NULL) {
            head = new TreeNode(val);
            ll.push_back(head);
            
            return -1;
        }
        else {
            TreeNode *curr = ll.front();
            if(curr->left == NULL) {
                curr->left = new TreeNode(val);
            }
            else if(curr->right == NULL) {
                curr->right = new TreeNode(val);
                
                ll.push_back(curr->left);
                ll.push_back(curr->right);
                
                ll.pop_front();
            }
            
            return curr->val;
        }
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
