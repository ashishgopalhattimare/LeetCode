// https://www.interviewbit.com/problems/next-pointer-binary-tree/
// Amazon, Microsoft

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    
    if(A == NULL) return;
    
    deque<TreeLinkNode*>ll;
    stack<TreeLinkNode*>st;
    
    ll.push_back(A);
    A->next = NULL;
    
    TreeLinkNode *prev = NULL, *curr;
    while(!ll.empty()) {
        while(!ll.empty()) {
            curr = ll.front();
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
            
            ll.pop_front();
        }
        prev = NULL;
        while(!st.empty()) {
            curr = st.top();
            curr->next = prev;
            
            ll.push_front(prev = curr);
            st.pop();
        }
    }
}

