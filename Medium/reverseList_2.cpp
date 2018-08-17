// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    
    ListNode *start;
    bool swapData;
    
    void reverseList(ListNode *head, int index, int n)
    {
        if(head == NULL) return;
        
        if(index < n) reverseList(head->next, index+1, n);
        
        if(start == head) swapData = false;
        
        if(swapData) {
            swap(start->val, head->val);
        }
        
        if(start->next == head) swapData = false;
        start = start->next;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        start = head;
        for(int i = 1; i < m; i++) {
            start = start->next;
        }
        
        swapData = true;
        reverseList(start, m, n);
        
        return head;
    }
};