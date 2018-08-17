// https://leetcode.com/problems/reorder-list/description/

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
    void reorderList(ListNode* head1) {
        
        if(head1 == NULL || head1->next == NULL) return;
        
        int len = 0;
        ListNode *ptr = head1, *prev, *next, *head2, *curr;
        
        while(ptr) {
            ptr = ptr->next;
            len++;
        }
        
        len = len/2 + len%2;
        
        prev = head1;
        ptr = prev->next;
        for(int i = 1; i < len; i++) {
            prev = ptr;
            ptr = ptr->next;
        }
        
        prev->next = NULL; // end of list1
        head2 = ptr; // start of list2
        
        
        // Reverse list2
        prev = NULL;
        while(head2) {
            next = head2->next;
            head2->next = prev;
            
            prev = head2;
            head2 = next;
        }
        head2 = prev;
        
        ptr = head1;
        while(ptr && head2) {
            curr = head2;
            head2 = head2->next;
            
            curr->next = ptr->next;
            ptr->next = curr;
            
            ptr = curr->next;
        }
    }
};