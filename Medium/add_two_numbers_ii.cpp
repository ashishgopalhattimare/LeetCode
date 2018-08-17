// https://leetcode.com/problems/add-two-numbers-ii/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode*>s1, s2, temp;
        
        ListNode *ptr;
        
        ptr = l1;
        while(ptr) {
            s1.push(ptr);
            ptr = ptr->next;
        }
        
        ptr = l2;
        while(ptr) {
            s2.push(ptr);
            ptr = ptr->next;
        }
        
        ListNode *front = NULL;
        
        int carry = 0, sum;
        while(!s1.empty() && !s2.empty()) {
            sum = (s1.top())->val + (s2.top())->val + carry;
            
            s1.pop(); s2.pop();
            
            if(sum >= 10) {
                carry = sum/10;
                sum = sum%10;
            } else {
                carry = 0;
            }
            
            ListNode *temp = new ListNode(sum);
            if(front) {
                temp->next = front;
            }
            front = temp;
        }
        
        while(!s1.empty()) {
            sum = (s1.top())->val + carry;
            s1.pop();
            
            if(sum >= 10) {
                carry = sum/10;
                sum = sum%10;
            } else {
                carry = 0;
            }
            
            ListNode *temp = new ListNode(sum);
            if(front) {
                temp->next = front;
            }
            front = temp;
        }
        
        while(!s2.empty()) {
            sum = (s2.top())->val + carry;
            s2.pop();
            
            if(sum >= 10) {
                carry = sum/10;
                sum = sum%10;
            } else {
                carry = 0;
            }
            
            ListNode *temp = new ListNode(sum);
            if(front) {
                temp->next = front;
            }
            front = temp;
        }
        
        if(carry) {
            ListNode *temp = new ListNode(carry);
            if(front) {
                temp->next = front;
            }
            front = temp;
        }
        
        return front;
    }
};