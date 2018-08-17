// https://leetcode.com/problems/split-linked-list-in-parts/description/

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        
        int len = 0;
        
        ListNode *ptr = root, *next, *r_ptr;
        while(ptr) {
            ptr = ptr->next;
            len++;
        }
        
        vector<ListNode*> result;
        if(k == 1) {
            result.push_back(root);
            
            return result;
        }
        if(root == NULL) {
            for(int i = 0; i < k; i++) {
                result.push_back(NULL);
            }
            return result;
        }
        
        if(k >= len) {
            ptr = root;
            while(ptr) {
                next = ptr->next;
                
                ptr->next = NULL;
                result.push_back(ptr);
                
                ptr = next;
            }
            
            for(int i = 0; i < k - len; i++) {
                result.push_back(NULL);
            }
        }
        else {
            int min_node = len / k;
            int extra = len % k;
            
            ptr = root;
            while(ptr) {
                r_ptr = ptr;
                for(int i = 0; i < min_node-1; i++) {
                    if(ptr) ptr = ptr->next;
                    else break;
                }
                
                // if extra present after devision, add one to the current set of linked list
                if(extra && ptr) {
                    ptr = ptr->next;
                    extra--;
                }
                
                // add null to this linked list and start again from the next;
                if(ptr) {
                    next = ptr->next;

                    ptr->next = NULL;
                    result.push_back(r_ptr);

                    ptr = next;
                }
                // if this is the last set from the linked list
                else {
                    result.push_back(r_ptr);
                }
            }
        }
        
        return result;
    }
};