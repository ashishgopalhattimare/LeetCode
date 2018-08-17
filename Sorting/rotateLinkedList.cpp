
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int temp;
    ListNode *start, *curr;
    bool swapPossible;
    
    void reverseList(ListNode *head, int k)
    {
        if(head == NULL) {
            
            // multiple of K
            if(k == 1) return;
            
            // not a multiple of K
            swapPossible = false;
            return;
        }
        
        // multiple of K
        if(k == 1) return;
        
        curr = curr->next;
        reverseList(head->next, k-1);
        
        // Odd Length swapping
        if(start == head) { swapPossible = false; }
        
        if(swapPossible) {
            temp = start->val;
            start->val = head->val;
            head->val = temp;
        }
        
        // Even length swapping
        if(start == head || start->next == head) {
            swapPossible = false;
        }
        start = start->next;
        
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        curr = head;
        while(curr) {
            start = curr;
            curr = curr->next;
            
            swapPossible = true;
            if(curr) reverseList(curr, k);
        }
        
        return head;
    }
};
