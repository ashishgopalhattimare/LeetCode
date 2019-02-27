// https://leetcode.com/problems/binary-tree-cameras/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int traverse(TreeNode *head, int *result)
    {
        if(head == NULL) {
            return 1;
        }
        
        int l = traverse(head->left, result);
        int r = traverse(head->right,result);
        
        // put camera at this node, and make the parent node visited - 3
        if(l == 2 || r == 2) {
            *result = *result + 1;
            printf("%d ", head->val);
            return 3;
        }
        
        int value = l + r;
        
        // put camera on the parent node
        if(value == 4) return 1;
        if(value == 2)return 2;
        
        return 1;
    }
    
    int minCameraCover(TreeNode* root) {
        
        int result = 0;
        
        int level = traverse(root, &result);
        
        return result + (level == 2); 
    }
};

/**

Input :

[0,1,2,3,4,5,6,7,8,null,9,null,null,10,null,null,null,null,null,11,12,null,13]
[1]
[1,2,3,null,4,null,5]

Camera on these nodes:
3 9 10 2 

2 3

output : 
4
1 (default)
2
**/
