// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode *ptr = head, *front = NULL, *rear = NULL;
        list<ListNode*>ll, temp;
        int sum, x;
        bool f;
        
        while(ptr) {
            if(ptr->val) {
                if(ll.empty()) ll.push_back(ptr);
                else {
                    sum = ptr->val;
                    f = false;
                    while(!ll.empty() && f == 0) {

                        sum += (x = ll.back()->val);

                        if(sum == 0) f = true;

                        temp.push_front(ll.back());
                        ll.pop_back();
                    }

                    if(f == false) { // if no subarray with sum 0
                        while(!temp.empty()) {
                            ll.push_back(temp.front());
                            temp.pop_front();
                        }
                        ll.push_back(ptr);
                    }
                    else while(!temp.empty()) temp.pop_back();
                }
            }
            ptr = ptr->next;
        }

        while(!ll.empty()) {
            ptr = ll.front();
            if(front == NULL) front = ptr;
            else rear->next = ptr;

            rear = ptr;
            ll.pop_front();
        }
        if(front) rear->next = NULL;
        
        return front;
    }
};