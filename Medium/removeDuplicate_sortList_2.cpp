// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *ptr = head, *curr, *prev = NULL;
        int value;
        
        while(ptr && ptr->next) {
            if(ptr->val == ptr->next->val) {
                value = ptr->val;
                
                if(prev == NULL) {
                    while(ptr && ptr->val == value) {
                        head = ptr->next;
                        ptr = head;
                    }
                }
                else {
                    while(ptr && ptr->val == value) {
                        curr = ptr->next;
                        prev->next = curr;
                        
                        ptr = prev->next;
                    } 
                }
            }
            else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};