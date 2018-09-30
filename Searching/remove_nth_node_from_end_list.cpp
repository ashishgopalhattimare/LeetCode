// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    
    ListNode *removeNode(ListNode *head, int& nn) {
        if(head == NULL) return NULL;
        
        head->next = removeNode(head->next, nn);
        if(nn-- == 1) {
            return head->next;
        }
        
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int nn = n;
        
        return removeNode(head, nn);
    }
};