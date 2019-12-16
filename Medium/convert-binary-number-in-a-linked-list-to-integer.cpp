// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        
        int result = 0;
        
        ListNode *ptr = head;
        while(ptr) {
            result = result * 2 + ptr->val;
            ptr = ptr->next;
        }
        
        return result;
    }
};