// https://leetcode.com/problems/odd-even-linked-list/
// Medium
// Extract Even nodes from the main list and push it at the end

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *ptr = head, *prev = NULL;
        ListNode *front = NULL, *rear;
        
        while(ptr && ptr->next) {
            if(front == NULL) {
                rear = (front = ptr->next);
            }
            else {
                rear = (rear->next = ptr->next);
            }
            
            ptr->next = rear->next;
            prev = ptr;
            ptr = ptr->next;
        }
        
        rear->next = NULL;
        
        if(ptr == NULL) prev->next = front;
        else ptr->next = front;
        
        return head;
    }
};
