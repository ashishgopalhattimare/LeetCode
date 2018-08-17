// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode *BST(int start, int end, vector<int>& nums)
    {
        if(start > end) return NULL;
        
        int mid = start + (end - start)/2;
        TreeNode *head = new TreeNode(nums[mid]);
        
        head->left = BST(start, mid-1, nums);
        head->right = BST(mid+1, end, nums);
        
        return head;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> v;
        ListNode *ptr = head;
        
        while(ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        return BST(0, v.size()-1, v);
    }
};