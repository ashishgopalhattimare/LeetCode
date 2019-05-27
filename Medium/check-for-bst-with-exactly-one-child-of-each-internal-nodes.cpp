// https://www.interviewbit.com/problems/check-for-bst-with-exactly-one-child-of-each-internal-nodes/#

struct Node {
    Node *left, *right;
    int val;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

void inorder(Node *head, int *prev, bool *result) {
    if(head == NULL) return;
    
    inorder(head->left, prev, result);
    if(*prev >= head->val) *result = false;
    *prev = head->val;
    inorder(head->right,prev, result);
}

bool inOrder(Node *root) 
{ 
    stack<Node *> s; 
    Node *curr = root;
    
    int prev = INT_MIN;
    while (curr || !s.empty()) {
        while (curr) { 
            s.push(curr);
            curr = curr->left;
        } 
        curr = s.top(); 
        s.pop(); 
        
        if(prev > curr->val) return false;
        prev = curr->val;
        curr = curr->right;
    }
    return true;
} 

string Solution::solve(vector<int>& A) {
    
    unordered_map<int, Node*>hash;
    for(int x : A) {
        hash[x] = new Node(x);
    }
    
    Node *currNode, *nextNode;
    for(int i = 0; i < A.size()-1; i++) {
        currNode = hash[A[i]];
        nextNode = hash[A[i+1]];
        
        if(currNode->left || currNode->right) return "NO";
        else {
            if(A[i] > A[i+1]) currNode->left = nextNode;
            else currNode->right = nextNode;
        }
    }
    
    /* Iterative Approach */
    // bool result = inOrder(hash[A[0]]);
    
    /* Recursive */
    // bool result = true;
    // int prev = INT_MIN;
    // inorder(hash[A[0]], &prev, &result);
    
    return result? "YES" : "NO";
}

