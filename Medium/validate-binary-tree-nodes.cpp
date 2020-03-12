// https://leetcode.com/problems/validate-binary-tree-nodes/
// Medium

class Solution {
public:
    
    bool possible;
    
    void func(vector<int>& child, vector<int>& parent) {
        for(int i = 0; i < child.size() && possible; i++) {
            if(child[i] != -1) {
                if(parent[child[i]] == -1) {
                    parent[child[i]] = i;
                }
                else possible = false;
            }
        }
        return;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        vector<int>parent(n, -1);
        possible = true;
        
        func(leftChild, parent);
        func(rightChild, parent);
        
        return (possible && count(parent.begin(), parent.end(), -1) == 1);
    }
};