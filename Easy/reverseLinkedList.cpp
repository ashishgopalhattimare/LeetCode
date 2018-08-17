/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:
    ListNode *start;
    bool swapPossible;
    
    void recursive(ListNode *head)
    {
        if(head == NULL) return;
        
        recursive(head->next);
        
        if(!swapPossible) return;
        
        if(start == head) swapPossible = false;
        
        if(swapPossible) {
            int temp = start->val;
            start->val = head->val;
            head->val = temp;
            
            if(start->next == head) swapPossible = false;
            
            start = start->next;
        }
        
        return;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        swapPossible = true;
        start = head;
        recursive(head);
        
        return head;
    }
};