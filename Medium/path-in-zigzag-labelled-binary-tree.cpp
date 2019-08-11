// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Easy
// Weekly Contest 143

struct Node {
    int val;
    Node *left, *right;
    
    Node(int val) : val(val), left(NULL), right(NULL) {}
};

bool preorder(Node *head, vector<int>& result, int label) {
    
    if(head == NULL) return false;
    
    result.push_back(head->val);
    if(head->val == label) {
        return true;
    }
    
    if(preorder(head->left , result, label)) return true;
    
    if(preorder(head->right, result, label)) return true;
    
    result.pop_back();
    return false;
}

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        
        bool rightDir = true;
        int value, size;
        
        Node *root = new Node(1);
        
        list<Node*>ll;
        ll.push_back(root);
        
        while(true) {
            
            // if list {4,5,6,7} - level Even, take the value from back to start next level value
            if(rightDir) value = ll.back()->val;
            // else list {3,2} - level Odd, take the value from front
            else value = ll.front()->val;
            
            if(value >= label) break; // if the value is already in the tree, break
            
            size = ll.size(); // get the current size of the list
            while(size && value <= label) {
                
                // Odd level {4,5,6,7}
                // Read the value from back
                // and push front of the list : result : {15,14,13,12,11,10,9,8} {4,5,6,7}
                //                              status :         in list           popped
                if(rightDir) {
                    Node *curr = ll.back();
                    ll.pop_back();
                    
                    curr->right = new Node(++value);
                    curr->left = new Node(++value);
                    
                    ll.push_front(curr->right);
                    ll.push_front(curr->left);
                }
                
                // Even level
                // E.g. if list is {3,2}
                // Read the value from back
                // and push front of the list : result : {3,2} {4,5,6,7}
                //                              status :  pop   in list
                else {
                    Node *curr = ll.front();
                    ll.pop_front();
                    
                    curr->left = new Node(++value);
                    curr->right = new Node(++value);
                    
                    ll.push_back(curr->left);
                    ll.push_back(curr->right);
                }
                size--;
            }
            
            rightDir = !(rightDir); // change the direction
        }
        
        // Simple Binary Tree Traversal
        vector<int>result;
        preorder(root, result, label);
        
        return result;
    }
};
