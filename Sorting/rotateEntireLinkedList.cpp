// https://leetcode.com/problems/rotate-list/description/

/**
Worst cases : when head is NULL
**/

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *temp;
        ListNode *ptr = head;
        int len = 0;
        
        while(ptr) {
            ptr = ptr->next;
            len++;
        }
        
        if(len == 1 || len == 0) return head;
        
        if(k >= len) k = k % len;
        
        while(k--) {
            ptr = head;
            while(ptr->next->next) {
                ptr = ptr->next;
            }
            
            temp = ptr->next;
            ptr->next = NULL;
            temp->next =head;
            head = temp;
        }
        
        return head;
    }
};
