// https://leetcode.com/problems/linked-list-cycle-ii/
// Medium

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
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode*>set;
        ListNode *ptr = head;
        while(ptr) {
            if(set.find(ptr) != set.end()) {
                break;
            }
            set.insert(ptr);
            ptr = ptr->next;
        }
        
        return ptr;
    }
};
