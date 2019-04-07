// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    
    ListNode* reverse(ListNode *head, int count, int k, int len) {
        
        if(count + k > len) return head;
        
        ListNode *prev = NULL, *curr = head, *next;
        
        for(int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            
            count++;
        }
        
        head->next = reverse(next, count, k, len);
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // 1->2->3->4->5
        
        int len = 0;
        ListNode* ptr = head;
        
        while(ptr) {
            ptr = ptr->next;
            len++;
        }
        
        if(k == 1 || len == 1 || len == 0) return head;
        
        head = reverse(head, 0, k, len);
        
        return head;
    }
};
