// https://leetcode.com/problems/middle-of-the-linked-list/
// Easy

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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *slow = head, *fast = head;
        int i;
        while(fast && fast->next) {
            for(i=0;i<2;i++) if(fast) fast=fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};