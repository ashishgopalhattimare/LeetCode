// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Medium

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    
    FindElements(TreeNode* rootTemp) {
        
        rootTemp->val = 0;
        fixTree(root = rootTemp);
    }
    
    bool find(int target) {
        return findValue(root, target);
    }

private:
    TreeNode *root;
    void fixTree(TreeNode *head) {
        
        if(head->left) {
            head->left->val = 2 *  head->val + 1;
            fixTree(head->left);
        }
        if(head->right) {
            head->right->val = 2 * head->val + 2;
            fixTree(head->right);
        }
        
        return;
    }
    
    bool findValue(TreeNode *head, int x) {
        if(head == NULL) return false;
        
        return (head->val == x) || findValue(head->left, x) || findValue(head->right, x);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */