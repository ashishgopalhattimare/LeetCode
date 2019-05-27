// Mock Test

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
    
    ListNode *reverse(ListNode* list) {
        ListNode *curr = list, *prev = NULL;
        ListNode *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void appendListNode(ListNode *result, ListNode *front, int value) {
        if(result == NULL) {
            front  = new ListNode(value);
            result = front;
        }
        else {
            front->next = new ListNode(value);
            front = front->next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode *result = NULL;
        ListNode *front;
        
        ListNode *p1 = l1, *p2 = l2;
        int carry = 0;
        int value;
        while(p1 && p2) {
            value = p1->val + p2->val + carry;
            
            if(result == NULL) result = front = new ListNode(value%10);
            else front = front->next = new ListNode(value%10);
            
            carry = value/10;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1) {
            value = ((p1) ? p1->val : 0);
            value+= carry;
            
            if(result == NULL) result = front = new ListNode(value%10);
            else front = front->next = new ListNode(value%10);
            
            carry = value/10;
            p1 = p1->next;
        }
        
        while(p2) {
            value = ((p2) ? p2->val : 0);
            value+= carry;
            
            if(result == NULL) result = front = new ListNode(value%10);
            else front = front->next = new ListNode(value%10);
            
            carry = value/10;
            p2 = p2->next;
        }
        
        while(carry) {
            front->next = new ListNode(carry%10);
            front = front->next;
            carry /= 10;
        }
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        return reverse(result);
    }
};
