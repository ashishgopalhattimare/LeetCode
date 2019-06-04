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
    
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head, *prev = NULL;
        ListNode *next;
        
        while(curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL) return head;
        
        head = reverse(head);
        
        ListNode *curr = head, *prev = NULL;
        while(--n) {
            curr = (prev = curr)->next;
        }
        
        if(curr == NULL) prev->next = NULL;
        else if(prev) prev->next = curr->next;
        else head = head->next;
        
        return reverse(head);
    }
};
