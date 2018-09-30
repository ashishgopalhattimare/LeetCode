// https://leetcode.com/problems/merge-two-sorted-lists/

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
    
    ListNode *front, *rear;
    
    void insert(int val) {
        ListNode *temp = new ListNode(val);
        
        if(front == NULL) {
            front = rear = temp;
        }
        else {
            rear->next = temp;
        }
        rear = temp;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        front = rear = NULL;
        
        ListNode *ptr1 = l1, *ptr2 = l2;
        
        while(ptr1 && ptr2) {
            
            ListNode *rem;
            if(ptr1->val < ptr2->val) {
                insert((rem = ptr1)->val);
                ptr1 = ptr1->next;
            }
            else {
                insert((rem = ptr2)->val);
                ptr2 = ptr2->next;
            }
            
            delete rem;
        }
        
        while(ptr1) {
            ListNode *rem;
            insert((rem = ptr1)->val);
            ptr1 = ptr1->next;
            delete rem;
        }
        while(ptr2) {
            ListNode *rem;
            insert((rem = ptr2)->val);
            ptr2 = ptr2->next;
            delete rem;
        }
        
        l1 = front;
        return l1;
    }
};