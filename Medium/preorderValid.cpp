// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution {
public:
    int index;
    bool possible;
    
    void traversal(vector<char>& tree)
    {
        if(index == tree.size()) possible = false;
        if(tree[index++] == 'o') {
            traversal(tree);
        }
        
        if(index == tree.size()) possible = false;
        if(tree[index++] == 'o') {
            traversal(tree);
        }
    }
    
    bool isValidSerialization(string preorder) {
        
        if(preorder.length() == 0) return true;
        
        vector<char>tree;
        
        // String to preorder array convertor
        for(int i = 0; i < preorder.length(); i++) {
            if(preorder[i] == '#') { // null
                tree.push_back('x');
            }
            else {
                tree.push_back('o'); // node
            }
            
            i++;
            while(preorder[i] != ',' && i < preorder.length()) { // move to next node/null
                i++;
            }
        }
        
        // if only root present
        if(tree.size() == 1) {
            return (tree[0] == 'x');
        }

        // more than 1 node but root is null
        if(tree[0] == 'x') return false;
        
        index = 1;
        possible = true;
        traversal(tree);
        
        return (possible && index == tree.size());
    }
};